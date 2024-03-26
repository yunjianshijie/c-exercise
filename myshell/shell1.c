#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <pwd.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
char *read_str(); // 打印开头，
void cdfun(int index, char a[40][40], char *cdhistory);
// void cut_str(char cut, char *a, char **str, int *index); //
bool shell(char a[40][40], int index, char *cd_history);
void exe(char *a, int num_pipe); //
void redirect(char *argv[], int argc);
void redirect_input(char *file_name);
void redirect_output(char *file_name, int index);
void home(char *a, char *home);
int main() {
    // signal(SIGINT, SIG_IGN);
    // signal(SIGQUIT, SIG_IGN);
    // signal(SIGTSTP, SIG_IGN); // 屏蔽信号
    char cd_history[300];
    getcwd(cd_history, sizeof(cd_history));
    while (1) {
        char *a = read_str(); // a为
        if (a == NULL) {
            free(a);
            continue;
        }
        char *b = (char *)malloc(sizeof(char) * (strlen(a) + 1));
        strcpy(b, a);
        char argv[40][40]; // 分割
        int argc = 0;
        const char delim[] = " ";
        char *token = strtok(a, delim);

        while (token != NULL && argc < 40) {
            strncpy(argv[argc], token, sizeof(argv[argc]) - 1);
            argv[argc][sizeof(argv[argc]) - 1] = '\0'; // 确保字符串以空字符结尾
            argc++;
            token = strtok(NULL, delim);
        }
        // printf("zhel%d\n", argc);
        int num_pipe = 0;
        for (int i = 0; i < argc; i++) {

            if (strcmp("|", argv[i]) == 0) {
                num_pipe++;
            }
            // printf("%s\n", argv[i]);
        }
        if (shell(argv, argc, cd_history)) {
            continue;
        }
        exe(b, num_pipe);
        printf("\n");
        free(a);
        free(b);
    }

    return 0;
}

char *read_str() { // 打印开头
    char *username = getlogin();
    printf("  \033[0;36m%s\033[0m @", username); // 用户名
    FILE *file = fopen("/proc/sys/kernel/hostname", "r");
    if (file == NULL) {
        return NULL;
    } else {
        char computername[257];
        fgets(computername, sizeof(computername), file);
        int len = strlen(computername);
        computername[len - 1] = '\0';
        printf(" \033[0;32m%s\033[0m ", computername); // 电脑名
    }
    struct passwd *pw = getpwuid(getuid());
    const char *home_dir = pw->pw_dir; // 获取用户目录
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        if (strcmp(pw->pw_dir, cwd) <= 0) {
            home(cwd, pw->pw_dir);
        }
        printf("in \033[1;33m%s\033[0m ", cwd); // 黄色
    }
    time_t rawTime;
    struct tm *localTime;
    time(&rawTime);
    localTime = localtime(&rawTime);
    printf("[%02d:%02d:%02d] ", localTime->tm_hour, localTime->tm_min,
           localTime->tm_sec);
    char *a = readline("\001\n\033[1;31m$\033[0m \002");
    if (a == NULL || a == "\n" || a == " ")
        return NULL;
    a[strlen(a)] = '\0';
    add_history(a);
    return a;
}
void cdfun(int index, char a[40][40], char *cdhistory) {
    // printf("%s\n", cdhistory);
    struct passwd *pw = getpwuid(getuid());
    const char *home_dir = pw->pw_dir; // 获取用户目录
    if (index > 2) {
        printf("cd: 没有那个文件或目录: %s", a[1]);
        return;
    } else if (index == 2) {
        char new_directory[256];
        strcpy(new_directory, a[1]);
        char h1[300];
        getcwd(h1, sizeof(h1));
        if (chdir(new_directory) == 0) {
            strcpy(cdhistory, h1);
        } else if (strcmp(new_directory, "-") == 0) {
            chdir(cdhistory);
            printf("%s\n", cdhistory);
            strcpy(cdhistory, h1);
        } else if (strcmp(new_directory, "~") == 0) {
            chdir(home_dir);
            strcpy(cdhistory, h1);
        } else {
            perror("chdir");
        }
    } else {
        chdir(home_dir);
    }
}
bool shell(char a[40][40], int index, char *cd_history) {
    if (strcmp(a[0], "exit") == 0) {
        exit(1);
    }
    if (strcmp(a[0], "cd") == 0) {
        cdfun(index, a, cd_history);
        return true;
    }
    if (index == 0) {
        return true;
    }
    return false;
}

void exe(char *a, int num_pipe) {
    int num_com = 0;
    const char delim[] = "|";
    // printf("a=%s\n", a);
    char *token = strtok(a, delim);
    char com[40][40];
    char **free_1;
    int free_argc;
    while (token != NULL) {
        // com[num_com] = (char *)malloc(strlen(token) + 1);
        strcpy(com[num_com], token);
        num_com++;
        token = strtok(NULL, delim);
        if (token == NULL) {
            break;
        }
    } // 隔管道
    if (num_com == 0) {
        return;
    }
    int pipefd[num_com - 1][2];
    for (int i = 0; i < num_com - 1; i++) { // 创建管道
        if (pipe(pipefd[i]) == -1) {
            perror("pipe");
            exit(4);
        }
    }
    pid_t child_pid;
    for (int i = 0; i < num_com; i++) { // 进程
        if ((child_pid = fork()) == -1) {
            perror("fork");
            exit(4);
        }                     // fork();
        if (child_pid == 0) { // 子进程里面
            if (num_com != 1) {
                if (i > 0) {
                    dup2(pipefd[i - 1][0], STDIN_FILENO);
                } // 连接前一个的写入
                if (i < num_com - 1) {
                    dup2(pipefd[i][1], STDOUT_FILENO);
                } // 自己连接读
                for (int i = 0; i < num_com - 1; i++) {
                    close(pipefd[i][1]);
                    close(pipefd[i][0]);
                } // 关闭所有管道
            }     // 如果有管道
            char *argv[40];
            free_1 = argv;
            int argc = 0;
            token = strtok(com[i], " ");
            while (token != NULL) {
                argv[argc] = (char *)malloc(sizeof(char) * strlen(token) + 1);
                strcpy(argv[argc++], token);
                token = strtok(NULL, " ");
            }
            free_argc = argc;
            // 分割了 ，要开始execvp了
            argv[argc] = NULL;
            redirect(argv, argc);
            execvp(argv[0], argv);
            perror("execvp");
            exit(EXIT_FAILURE);
            for (int i = 0; i < free_argc; i++) {
                free(free_1[i]);
            }
        }

        // else { // 父进程

        //     wait(NULL);
        //     printf("父进程停止wait%d\n", i);
        // }
    } // 循环结束
    for (int i = 0; i < num_com - 1; i++) {
        close(pipefd[i][1]);
        close(pipefd[i][0]);
    } // 关闭
    for (int i = 0; i < num_com; i++) {
        pid_t pid;
        pid = wait(NULL);
        printf(":: %d/%d\n", i, num_com - 1);
        if (strstr(com[i], "&"))
            printf("%d    %s", pid, com[i]);
    }
}
void redirect(char *argv[], int argc) {

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "<") == 0) {
            redirect_input(argv[i + 1]);
            argv[i + 1] = NULL;
            argv[i] = NULL;
            i += 2;
            continue;
        }
        if (strcmp(argv[i], ">") == 0) {
            redirect_output(argv[i + 1], 0);
            argv[i + 1] = NULL;
            argv[i] = NULL;
            i += 2;
            continue;
        }
        if (strcmp(argv[i], ">>") == 0) {
            redirect_output(argv[i + 1], 1);
            argv[i + 1] = NULL; // argvi+1为文件
            argv[i] = NULL;
            i += 2;
            continue;
        }
    }
}
void redirect_input(char *file_name) {
    int fd = open(file_name, O_RDONLY);
    if (dup2(fd, 0) == -1) {
        perror("dup2");
        exit(4);
    }
}
void redirect_output(char *file_name, int index) {
    int fd;
    if (index == 0) {
        fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    } else if (index == 1) {
        fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
    }
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
    }
    close(fd);
}
void home(char *a, char *home) { // 改home文件成~;
    int lenhome = strlen(home);
    int len = strlen(a);
    a[0] = '~';
    for (int i = 1; i < len - lenhome + 1; i++) {
        a[i] = a[i + lenhome - 1];
    }
    a[len - lenhome + 1] = '\0';
}
