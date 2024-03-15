#include "shell.h"
int munu[10]; //
int main() {

    struct termios term; // 结构体储存终端中各种属性
    tcgetattr(0, &term); // 0为文件描述符，标准输入L
    term.c_cc[VEOF] = 0;
    tcsetattr(0, TCSANOW, &term);
    // 屏蔽ctrl+D
    signal(SIGINT, sigint_handler);
    char cdhistory[30] = "/"; // cd -上一个cd的目录
    char history[30][30];
    int top_history = 0; // 将history历史变成栈
    while (1) {
        char *b = printfs();
        int index = 0;
        char **a = scanfs(&index, b);
        if (index == 0) {
            continue;
        }
        if (strcmp(a[0], "cd") == 0) {
            cdfun(index, a, cdhistory);
            continue;
        }
        if (strcmp(a[0], "as") == 0) {
            printf("没有汇编文件哦~\n");
            continue;
        }
        if (index == 1 && strcmp(a[0], "exit") == 0) {
            exit(2);
        }
        // 处理
        int h = find(index, a); // 找字符
        if (h == -1) {
            printf("输入格式问题\n");
            continue;
        }
        if (h != 0) {
            printf("此时逆袭\n"); // h有
            if (h ==)

        } else {
            pid_t child_pid;
            child_pid = fork();
            if (child_pid == -1) {
                perror("fork");
            } else if (child_pid == 0) {
                // FILE *file;
                execvp(a[0], a);
                exit(1);
                // printf("sdkf");
            } else {
                parent_code(child_pid);
            }
        }
        fflush(stdin);
        free(a);
        free(b);
    }

    return 0;
}
void parent_code(int chilepid) {
    int wait_rv;
    int child_status;
    // int high_8, low_7, bit_7;
    // printf("zaizher;\n");
    wait_rv = wait(&child_status);
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

char *printfs() { // 打印开头
    // char *dfh = getenv("HOME");
    // printf("%s", dfh);
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

    // readline("hudsaj");
    // add_history("sdakd");

    time_t rawTime;
    struct tm *localTime;
    time(&rawTime);
    localTime = localtime(&rawTime);
    printf("[%02d:%02d:%02d] ", localTime->tm_hour, localTime->tm_min,
           localTime->tm_sec);
    char *a = (char *)malloc(sizeof(char) * 40);
    a = readline("\n\033[1;31m$\033[0m ");
    add_history(a);
    // printf("%s  zz\n", a);
    return a;
}

char **scanfs(int *index, char *a) {
    char **str = (char **)malloc(sizeof(char *) * 100);
    // char a[1000];
    char ch;
    int i = 0;
    // printf("ksl\n");
    // while ((ch = getchar()) != '\n') {
    //     a[i++] = ch;
    //     // printf("%d  ", i);
    // }
    // printf("a======%s\n", a);
    // a[i] = '\0';
    const char delim[] = " "; // 使用空格作为分隔符
    char *token;
    token = strtok(a, delim);
    int j = 0;
    while (token != NULL) {
        int len = strlen(token);
        str[j] = (char *)malloc(sizeof(char) * (len + 1));
        strcpy(str[j], token);
        // printf("11 %s \n", str[j]);
        j++;
        token = strtok(NULL, delim);
    }
    *(index) = j;
    return str;
}

void cdfun(int index, char **a, char *history) {
    struct passwd *pw = getpwuid(getuid());
    const char *home_dir = pw->pw_dir; // 获取用户目录
    if (index > 2) {
        printf("cd: 没有那个文件或目录: %s", a[1]);
        return;
    } else if (index == 2) {
        char new_directory[256];
        strcpy(new_directory, a[1]);
        if (chdir(new_directory) == 0) {
            // printf("Changed directory to: %s\n", new_directory);
        } else if (strcmp(new_directory, "-") == 0) {
            chdir("..");
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd)) != NULL)
                printf("%s\n", cwd);
        } else {
            perror("chdir");
        }
    } else {
        chdir(home_dir);
    }
}

void sigint_handler() {
    // 屏蔽ctrl+c
    // printf("再玩一会吧～\n");
}
void mypipe() {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

bool judge(int h, char **a, int index, int i)
// 判断重定向，管道，&后台进行，是否输入正确
{
    if (h == 0) {
        return true;
    }
    if (h == 1 || h == 3 || h == 6) {
        if (i == index - 1) {
            return false;
        } else {
            return true;
        }
    }
    if (h == 2 || h == 4) {
        if (i == 0) {
            return false;
        } else {
            return true;
        }
    }
    if (h == 5) {
        if (i == 0 || i == index - 1) {
            return false;
        } else {
            return true;
        }
    }
}

// bool judge(int h, char **a, int index, int i)
int find(int index, char **a) {

    for (int i = 0; i < index; i++) {
        if (strcmp(a[i], ">") == 0) {
            if (judge(1, a, index, i))
                return 1;
            return -1;
        } else if (strcmp(a[i], "<") == 0) {
            if (judge(2, a, index, i))
                return 2;
            return -1;
        } else if (strcmp(a[i], ">>") == 0) {
            if (judge(3, a, index, i))
                return 3;
            return -1;
        } else if (strcmp(a[i], "<<") == 0) {
            if (judge(4, a, index, i))
                return 4;
            return -1;
        } else if (strcmp(a[i], "|") == 0) {
            if (judge(5, a, index, i))
                return 5;
            return -1;
        } else if (strcmp(a[i], "&") == 0) {
            if (judge(6, a, index, i))
                return 6;
            return -1;
        }
    } // 找字符
    return 0;
}
void output1(char *file_name, char **command) {
    FILE *file = fopen(file_name, "w");

    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    // 将标准输出重定向到文件
    int fd = fileno(file);
    dup2(fd, STDOUT_FILENO);
    int pid_child = fork();
    if (pid_child == -1) {
        perror("fork");
    } else if (pid_child == 0) {
        execvp("ls", command);
        exit(1);
    } else {
        int wait_rv;
        int stats;
        wait(&stats);
    }
    fclose(file);
    fork(); // 这个是
    return;
}