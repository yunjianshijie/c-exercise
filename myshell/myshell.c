#include "shell.h"
int munu[10]; //
int main() {

    struct termios term; // 结构体储存终端中各种属性
    tcgetattr(0, &term); // 0为文件描述符，标准输入L
    term.c_cc[VEOF] = 0;
    tcsetattr(0, TCSANOW, &term);
    // 屏蔽ctrl+D
    signal(SIGINT, sigint_handler);
    char cdhistory[300]; // cd -上一个cd的目录

    getcwd(cdhistory, sizeof(cdhistory));
    int count = 0;
    while (1) {
        int number_ch[10] = {0}; // 一从前到后编号，100*位
        int number = 0;
        printf(" "); // 如果不打印这个就不行
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
        // number_ch数量
        int h = find(index, a, number_ch, &number); // 找字符
        char ***ab = (char ***)malloc(sizeof(char **) * number);
        int ab_len[50];
        if (h == -1) {
            printf("输入格式问题\n");
            continue;
        } else if (h != 0) {
            printf("!!!!!有 |  < > >> &\n"); // h有

            for (int i = 0; i < number + 1; i++) {
                // printf("zjipj\n");
                if (i == 0) {
                    ab[i] = find_command(a, 0, (number_ch[i] / 10) - 1);
                    ab_len[i] = number_ch[i] / 10;
                    // printf("ab%d : %d->%d  %d \n", i, 0, number_ch[i] / 10 -
                    // 1,
                    //        ab_len[i]);
                } else if (i == number) {
                    ab[i] =
                        find_command(a, (number_ch[i - 1] / 10) + 1, index - 1);
                    ab_len[i] = index - 1 - number_ch[i - 1] / 10;
                    // printf("ab%d : %d->%d  %d\n ", i, number_ch[i - 1] / 10 +
                    // 1,
                    //        index - 1, ab_len[i]);
                } else {
                    ab[i] = find_command(a, number_ch[i - 1] / 10 + 1,
                                         number_ch[i] / 10 - 1);
                    ab_len[i] = number_ch[i] / 10 - number_ch[i - 1] / 10 - 1;
                    //
                    // printf("ab%d : %d->%d  %d\n ", i, number_ch[i - 1] / 10,
                    //        number_ch[i] / 10, ab_len[i]);
                }
                // printf("~~~~~~~~~~%d\n", ab_len[i]);
                // printf2(ab[i], ab_len[i]);
                // if (i != number)
                //     printf("%d\n", number_ch[i]);
            }
            // number_ch 是字符性质 number 是个数
            for (int i = 0; i < number; i++) {

                if (number_ch[i] % 10 == 1) { // i是前面,i+1是后面
                    output1(ab[i + 1][0], ab[i]);
                }
                if (number_ch[i] % 10 == 3) { // i是前面,i+1是后面
                    output2(ab[i + 1][0], ab[i]);
                }
                if (number_ch[i] % 10 == 2) {
                    output3(ab[i + 1][0], ab[i]);
                }
            }
            //

        } else {
            pid_t child_pid;
            child_pid = fork();
            if (child_pid == -1) {
                perror("fork");
            } else if (child_pid == 0) {
                // FILE *file;
                printf("zheli2   %s\n", a[0]);
                // printf("%s", a[1]);
                execvp(a[0], a);
                exit(1);
                // printf("sdkf");
            } else {
                parent_code(child_pid);
                // printf("%d\n", child_pid);
            }
        }
        fflush(stdin);

        // for (int i = 0; i <= index; i++) {
        //     free(a[i]);
        // }
        // free(a);  // a个数为index
        // free(b);  // b是整体
        // free(ab); // ab[]number,[]
        // return 0;
    }

    return 0;
}

void parent_code(int chilepid) {
    int wait_rv;
    int child_status;
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
    printf("\n\033[1;31m$\033[0m ");
    char *a = (char *)malloc(sizeof(char) * 40);
    char ch;
    int count = 0;
    while ((ch = getchar()) != '\n') {
        a[count++] = ch;
    }
    a[count] = '\0';
    // scanf("%s", a);
    // char *a = readline
    // add_history(a);
    printf("%s  zz\n", a);
    return a;
}

char **scanfs(int *index, char *a) {
    char **str = (char **)malloc(sizeof(char *) * 100);
    // char a[1000];
    char ch;
    int i = 0;
    //  printf("ksl\n");
    //  while ((ch = getchar()) != '\n') {
    //      a[i++] = ch;
    //      // printf("%d  ", i);
    //  }
    //  printf("a======%s\n", a);
    //  a[i] = '\0';
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

void cdfun(int index, char **a, char *cdhistory) {
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
        } else {
            perror("chdir");
        }
    } else {
        chdir(home_dir);
    }
}

void sigint_handler() {
    exit(3);
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
int find(int index, char **a, int *number, int *n) {
    int ret = 0;
    int count = 0;
    for (int i = 0; i < index; i++) {
        if (strcmp(a[i], ">") == 0) {
            if (!judge(1, a, index, i))
                return -1;
            ret = 1;
            number[count] = 10 * i;
            number[count++] += 1;
        } else if (strcmp(a[i], "<") == 0) {
            if (!judge(2, a, index, i))
                return -1;
            ret = 2;
            number[count] = 10 * i;
            number[count++] += 2;
        } else if (strcmp(a[i], ">>") == 0) {
            if (!judge(3, a, index, i))
                return -1;
            ret = 3;
            number[count] = 10 * i;
            number[count++] += 3;
        } else if (strcmp(a[i], "<<") == 0) {
            if (!judge(4, a, index, i))
                return -1;
            ret = 4;
            number[count] = 10 * i;
            number[count++] += 4;
        } else if (strcmp(a[i], "|") == 0) {
            if (!judge(5, a, index, i))
                return -1;
            ret = 5;
            number[count] = 10 * i;
            number[count++] += 5;
        } else if (strcmp(a[i], "&") == 0) {
            if (!judge(6, a, index, i))
                return -1;
            ret = 6;
            number[count] = 10 * i;
            number[count++] += 6; // 10位是第n个，个位是>>
        }

    } // 找字符
    *n = count;
    return ret;
}

void output1(char *file_name, char **command) {
    FILE *file = fopen(file_name, "w");

    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    // 将标准输出重定向到文件
    int fd = fileno(file);
    printf("~~~~~  %s  %d\n", file_name, fd);
    dup2(fd, STDOUT_FILENO);
    printf("~~~~~~~\n");
    int pid_child = fork();
    if (pid_child == -1) {
        perror("fork");
    } else if (pid_child == 0) {
        execvp(command[0], command);
        exit(1);
    } else {
        int wait_rv;
        int stats;
        wait(&stats);
    }
    fclose(file);
    freopen("/dev/tty", "w", stdout);
    // fork(); // 这个是
    return;
}
void output2(char *file_name, char **command) {
    FILE *file = fopen(file_name, "a");

    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    // 将标准输出重定向到文件
    int fd = fileno(file);
    printf("~~~~~  %s  %d\n", file_name, fd);
    dup2(fd, STDOUT_FILENO);
    int pid_child = fork();
    if (pid_child == -1) {
        perror("fork");
    } else if (pid_child == 0) {
        execvp(command[0], command);
        exit(1);
    } else {
        int wait_rv;
        int stats;
        wait(&stats);
    }
    fclose(file);
    freopen("/dev/tty", "w", stdout); // 将输出进入终端
    // fork(); // 这个是
    return;
}
void output3(char *file_name, char **command) {
    printf("zheli\n");
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
    }
    if (dup2(fd, 0) == -1) {
        perror("open");
    } // 0为标准输入
    close(fd);
    // 把文件读入缓存，关闭
    int fd1 = open("filewenjain", O_RDWR);
    if (fd1 == -1) {
        perror("open");
    }
    if (dup2(fd1, 1) == -1) {
        perror("open");
    }
    int pid_child = fork();

    if (pid_child == -1) {
        perror("fork");
    } else if (pid_child == 0) {
        // char *args[] = {command[0], NULL};
        //
        execvp(command[0], command);
        char ch[1024];
        size_t buffernumber;
        while (buffernumber = read(fd1, ch, 1024) > 0) {
            write(STDOUT_FILENO, ch, buffernumber);
        };
        freopen("/dev/tty", "w", stdout);
        exit(2);
    } else {
        int stats;
        wait(&stats);
        // printf("父进程:output3\n");
        //  exit(1);
    }
}

char **find_command(char **a, int left, int right) {
    char **ret = (char **)malloc(sizeof(char *) * (right - left + 1));
    for (int i = 0; i <= right - left; i++) {
        int len = strlen(a[left + i]);
        ret[i] = (char *)malloc(sizeof(char) * len);
        strcpy(ret[i], a[left + i]);
    }
    return ret;
}

void printf2(char **a, int index) {
    for (int i = 0; i < index; i++) {
        printf("%s\n", a[i]);
    }
}
