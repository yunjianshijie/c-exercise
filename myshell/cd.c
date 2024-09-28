#include <fcntl.h>
#include <pwd.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAXARGS 50
#define ARGLEN 100

void set_prompt(char *prompt);               // 获取命令提示符
int cd(char *path, char *pathname);          // cd命令
void redirect_input(char *input);            // 输入重定向
void redirect_output(char *output, int add); // 输出重定向
void find(int argc, char *argv[]);           // 寻找特殊符号
void excute(char *cmdline);                  // 执行命令

char formerpath[256]; // 上一次工作目录

int main() {
    // 屏蔽信号
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    while (1) {
        char *argv[MAXARGS + 1], *cmdline, pathname[256], prompt[150];
        int argc = 0;
        getcwd(pathname, sizeof(pathname));
        set_prompt(prompt);
        fflush(stdin);
        if (!(cmdline = readline(prompt)))
            break;
        add_history(cmdline);

        char buf[ARGLEN];
        strcpy(buf, cmdline);
        argv[0] = cmdline;
        for (int i = 0; i < MAXARGS - 1; i++)
            argv[i] = strtok_r(argv[i], " ", &argv[i + 1]);
        while (argv[argc])
            argc++;

        int pipe_num = 0, back = 0;
        for (int i = 0; i < argc; i++) {
            if (!strcmp(argv[i], "|"))
                pipe_num++;
        }
        if (argc == 0) {
            free(cmdline);
            continue;
        }
        if (!strcmp(argv[0], "exit")) {
            free(cmdline);
            break;
        }
        if (!strcmp(argv[0], "cd")) {
            if (argc == 1)
                argv[1] = "~";
            cd(argv[1], pathname);
        } else {
            excute(buf);
        }
        free(cmdline);
    }
    return 0;
}

void set_prompt(char *prompt) {
    // 获取主机名
    char hostname[100];
    if (gethostname(hostname, sizeof(hostname))) {
        perror("gethostname");
        exit(EXIT_FAILURE);
    }

    // 获取用户名
    struct passwd *user;
    char *username;
    user = getpwuid(getuid());
    username = user->pw_name;

    // 获取当前工作目录
    char cwd[100];
    char buf[100];
    getcwd(buf, sizeof(buf));
    char *home = getenv("HOME");
    size_t len = strlen(home);
    if (!strncmp(buf, home, len)) {
        strcpy(cwd, "~");
        strcat(cwd, buf + len);
    } // 将home目录改成~

    // 获取时间
    time_t curtime;
    time(&curtime);
    char time[10];
    strncpy(time, ctime(&curtime) + 11, 8);

    sprintf(prompt,
            "\n\e[40;33m %s@%s \e[0m\e[44;30m %s \e[0m\e[47;30m %s "
            "\e[0m\n\e[32m %s \e[0m",
            username, hostname, cwd, time, "$");
}

int cd(char *targetpath, char *pathname) {
    if (!strcmp(targetpath, "-"))
        targetpath = formerpath;
    else
        strcpy(formerpath, pathname);

    if (!strncmp(targetpath, "~", 1)) {
        char *home = getenv("HOME");
        char path[256];
        strcpy(path, home);
        strcat(path, targetpath + 1);
        targetpath = path;
    } // chdir无法识别~,需将~改为home路径

    if (chdir(targetpath) == -1)
        perror("chdir");
}

void redirect_input(char *input) {
    int fd, newfd;
    fd = open(input, O_RDONLY);
    newfd = dup2(fd, 0);
    if (newfd == -1) {
        fprintf(stderr, "Could not redirect input\n");
        exit(EXIT_FAILURE);
    }
}

void redirect_output(char *output, int add) {
    int fd, newfd;
    if (!add)
        fd = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else
        fd = open(output, O_WRONLY | O_CREAT | O_APPEND, 0644);
    newfd = dup2(fd, 1);
    if (newfd == -1) {
        fprintf(stderr, "Could not redirect output\n");
        exit(EXIT_FAILURE);
    }
}

void find(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "<")) {
            redirect_input(argv[i + 1]);
            argv[i] = NULL;
            argv[i + 1] = NULL;
            i += 2;
            continue;
        }
        if (!strcmp(argv[i], ">")) {
            redirect_output(argv[i + 1], 0);
            argv[i] = NULL;
            argv[i + 1] = NULL;
            i += 2;
            continue;
        }
        if (!strcmp(argv[i], ">>")) {
            redirect_output(argv[i + 1], 1);
            argv[i] = NULL;
            argv[i + 1] = NULL;
            i += 2;
            continue;
        }
        if (!strcmp(argv[i], "&")) {
            redirect_input("/dev/null");
            redirect_output("/dev/null", 0);
            argv[i] = NULL;
            i += 2;
        }
    }
}

void excute(char *cmdline) {
    // 按 | 分割命令
    int cmd_num = 0;
    char *cmd[MAXARGS];
    cmd[0] = cmdline;
    for (int i = 0; i < MAXARGS; i++)
        cmd[i] = strtok_r(cmd[i], "|", &cmd[i + 1]);
    while (cmd[cmd_num])
        cmd_num++;
    int pipe_num = cmd_num - 1;

    // 建立管道
    int pipefd[pipe_num][2];
    for (int i = 0; i < pipe_num; i++) {
        if (pipe(pipefd[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    pid_t pid;
    for (int i = 0; i < cmd_num; i++) {
        if ((pid = fork()) == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        // 子进程
        if (pid == 0) {
            if (pipe_num) {
                // 第一个命令
                if (i == 0) {
                    // 关闭读数据端，并重定向写数据端
                    dup2(pipefd[i][1], 1);
                }

                // 最后一个命令
                else if (i == cmd_num - 1) {
                    // 关闭读数据端，并重定向写数据端
                    dup2(pipefd[i - 1][0], 0);
                }

                // 中间的命令
                else {
                    // 重定向读数据端
                    dup2(pipefd[i - 1][0], 0);

                    // 重定向写数据端
                    dup2(pipefd[i][1], 1);
                }

                // 关闭所有管道
                for (int i = 0; i < pipe_num; i++) {
                    close(pipefd[i][0]);
                    close(pipefd[i][1]);
                }
            }

            char *argv[MAXARGS];
            int argc = 0;
            argv[0] = cmd[i];
            for (int j = 0; j < MAXARGS - 1; j++)
                argv[j] = strtok_r(argv[j], " ", &argv[j + 1]);
            while (argv[argc])
                argc++;

            find(argc, argv);
            if (!strcmp(argv[0], "ls")) {
                int index = 1;
                if (argv[1])
                    index = 2;
                argv[index++] = (char *)"--color=auto";
            } // 给ls命令上色
            execvp(argv[0], argv);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }

    // 父进程
    for (int i = 0; i < pipe_num; i++) {
        close(pipefd[i][0]);
        close(pipefd[i][1]);
    }
    for (int i = 0; i < cmd_num; i++) {
        pid_t pid;
        int status;
        pid = wait(&status);

        if (strstr(cmd[i], "&"))
            printf("%d    %s", pid, cmd[i]);
    }
}