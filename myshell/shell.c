#include "shell.h"
int main() {

    struct termios term; // 结构体储存终端中各种属性
    tcgetattr(0, &term); // 0为文件描述符，标准输入L
    term.c_cc[VEOF] = 0;
    tcsetattr(0, TCSANOW, &term);
    // 屏蔽ctrl+D
    signal(SIGINT, sigint_handler);
    char cdhistory[300]; // cd -上一个cd的目录
    getcwd(cdhistory, sizeof(cdhistory));
    while (1) {
        int number_ch[10] = {0}; // 一从前到后编号，100*位
        int number = 0;
        printf("\n");
        char *b = printfs(); // 获取字符串
        if (b == NULL) {
            continue;
        }
        int index = 0;
        int count = 0; // 有多少个管道符+1
        const char *strpipe = "|";
        char *str = strstr(b, strpipe);

        if (str != NULL) {
            // printf("有管道\n");
            char **command1s = cut_pipe(b, &count);
            char **commands[10];
            int index1[10];
            // printf("count =%d", count);
            for (int i = 0; i < count; i++) {
                commands[i] = cut_str(index1 + i, command1s[i]);
                commands[i][*(index1 + i)] = NULL;
            }
            // count++;
            int pipes[count - 1][2];
            pid_t child_pid;
            for (int i = 0; i < count - 1; i++) {
                if (pipe(pipes[i]) == -1) {
                    perror("pipe");
                    exit(EXIT_FAILURE);
                }
            }
            // count个命令
            for (int i = 0; i < count; i++) {
                printf("%d\n", i);
                child_pid = fork();
                if (child_pid == -1) {
                    perror("fork");
                } else if (child_pid == 0) {

                    if (i > 0) {

                        close(pipes[i - 1][1]); // 关闭前一个管道的写入端
                        dup2(pipes[i - 1][0],
                             STDIN_FILENO); //
                        // 重定向前一个管道的读取端到标准输入
                        close(pipes[i - 1][0]);
                    }

                    if (i != count - 1) {
                        close(pipes[i][0]); // 关闭当前管道的读取端
                        dup2(pipes[i][1],
                             STDOUT_FILENO); //
                        // 重定向当前管道的写入端到标准输出
                        close(pipes[i][1]); // 再关写入
                    }

                    command(commands[i], index1[i], cdhistory);
                    exit(3);
                    // execvp(commands[i][0], commands[i]);
                }
            }
            for (int i = 0; i < count - 1; i++) {
                close(pipes[i][0]);
                close(pipes[i][1]);
            } // 关闭所有管道

            for (int i = 0; i < count; i++) {
                wait(NULL);
            }

        } else { // 就必须有空格才能
            char **a = cut_str(&index, b);
            command(a, index, cdhistory);
        }
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
    // char *a = (char *)malloc(sizeof(char) * 40);
    char *a = readline("\001\n\033[1;31m$\033[0m \002");
    if (a == NULL || a == "\n" || a == " ")
        return NULL;
    a[strlen(a)] = '\0';
    add_history(a);
    // printf("\n\033[1;31m$\033[0m ");

    // char ch;
    // int count = 0;
    // fflush(stdin);
    // getchar();
    // sleep(3);
    // while ((ch = getchar()) != '\n') {
    //     a[count] = ch;
    //     count++;
    //     // printf("%d", count);
    // }
    // a[count] = '\0';
    // printf("%s  zz\n", a);

    return a;
}

char **cut_str(int *index, char *a) {
    char **str = (char **)malloc(sizeof(char *) * 100);
    // char a[1000];
    char ch;
    const char delim[] = " "; // 使用空格作为分隔符
    char *token;
    token = strtok(a, delim);
    int j = 0;
    while (token != NULL) {
        int len = strlen(token);
        str[j] = (char *)malloc(sizeof(char) * (len + 1));
        strcpy(str[j], token);
        // printf("11 %s  %d \n", str[j], j);
        j++;
        token = strtok(NULL, delim);
    }

    *(index) = j;
    return str;
}
char **cut_pipe(char *strin, int *count) {
    int i = 0;
    const char delim[] = "|";
    char *token;
    token = strtok(strin, delim);
    char **str = (char **)malloc(sizeof(char *) * 20);
    while (token != NULL) {
        int len = strlen(token);
        str[i] = (char *)malloc(sizeof(char) * (len + 1));
        strcpy(str[i], token);
        i++;
        token = strtok(NULL, delim);
    }
    *(count) = i;
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
            // printf("Changed directory to: %s\n", new_directory);
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
int find(int index, char **a, int *number,
         int *n) { // index 个数，a二维数组，number 数组_状态 ，n为个数
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

void output1(char *file_name, char **command) { ///
    // printf("12345  %s\n", file_name);
    FILE *file = fopen(file_name, "w");

    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    // 将标准输出重定向到文件
    int fd = fileno(file);
    // printf("~~~~~  %s  %d\n", file_name, fd);
    // printf("dsdd  %s\n", command[0]);

    int pid_child = fork();
    if (pid_child == -1) {
        perror("fork");
    } else if (pid_child == 0) {
        dup2(fd, STDOUT_FILENO);

        execvp(command[0], command);
        exit(1);
    } else {
        int wait_rv;
        int stats;
        waitpid(pid_child, &stats, 0);
    }
    fclose(file);
    // freopen("/dev/tty", "w", stdout);
    //  fork(); // 这个是
    return;
}
void output2(char *file_name, char **command) {
    int fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0777);
    printf("~~~~~  %s  %d  %s\n", file_name, fd, command[0]);

    int pid_child = fork();
    if (pid_child == -1) {
        perror("fork");
    } else if (pid_child == 0) {
        dup2(fd, STDOUT_FILENO);
        printf("1111\n");
        close(fd);
        execvp(command[0], command);
        exit(1);
    } else {
        int wait_rv;
        int stats;

        waitpid(pid_child, &stats, 0);
        printf("1111111111111\n");
    }

    // freopen("/dev/tty", "w", stdout);
    //  fork(); // 这个是
    return;
}
void output3(char *file_name, char **command,
             int command_num) { // '<' 文件 ，命令， 命令长度
    // int len = strlen(file_name);
    // command[command_num] = (char *)malloc(sizeof(char) * len);
    // printf("%d\n", command_num);
    // strcpy(command[command_num], file_name);
    // command[command_num] = NULL;
    // // command_num++;

    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
    } else if (child_pid == 0) {
        // printf("ff");
        int fd = open(file_name, O_RDONLY); // 将标准输出重定向到文件
        // int fd2 = dup(0);
        dup2(fd, STDIN_FILENO);
        close(fd);
        execvp(command[0], command);
        // exit(2);
    } else {
        int stats;
        waitpid(child_pid, &stats, 0);
        // wait(&stats);
        printf("\n");
    }

    // dup2(fd2, STDOUT_FILENO);
    //  printf("d\n");
}

// void output4(char **command1, char **command2, int index1, int index2,
//              char *cdhistory) {
//     int pipefd[2];
//     pid_t child_pid;
//     if (pipe(pipefd) == -1) {
//         perror("pipe");
//     }
//     child_pid = fork();
//     if (child_pid == -1) {
//         perror("fork"); // 错误
//     } else if (child_pid == 0) {
//         close(pipefd[1]);   // 关读入
//         dup2(pipefd[0], 1); // 将文件描述符与输出流连接
//         close(pipefd[2]);
//         command(command1, index1, cdhistory); //
//     } else {
//         close(pipefd[0]); // 关写入 ，这里只读
//     }
// }

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
        printf("%d", i);
        printf(" %s\n", a[i]);
    }
}

int isSystemCommand(const char *command) {
    char buffer[512];
    char cmd[512];

    // 构建要执行的系统命令
    sprintf(cmd, "which %s > /dev/null 2>&1", command);

    // 执行系统命令
    int result = system(cmd);

    // 根据返回值判断命令是否为系统命令
    if (result == 0) {
        return 1; // 是系统命令
    } else {
        return 0; // 不是系统命令
    }
}

int command(char **a, int index, char *cdhistory) {
    // printf("111111111~~~~~~~~~~~~~");
    char *ab[3][5]; // number_ch 是字符性质 n 是个数,ab_len是长度 ab多少个
    a[index] = 0;
    if (index == 0) {
        return 1;
    }
    if (strcmp(a[0], "cd") == 0) {
        cdfun(index, a, cdhistory);
        return 1;
    }
    if (strcmp(a[0], "as") == 0) {
        printf("没有汇编文件哦~\n");
        return 1;
    }
    if (index == 1 && strcmp(a[0], "exit") == 0) {
        exit(2);
    }
    int number_ch[8];
    int number[8];
    memset(number, 0, 8);
    int n = 0;
    // int find(int index, char **a, int *number, int *n);
    if (find(index, a, number_ch, &n) == -1) {
        printf("格式错误");
        exit(3);
    }
    // printf("(number_ch[i + 1] / 10) - (number_ch[i] / 10)=%d\n",
    //        (number_ch[1] / 10)); //- (number_ch[0] / 10)
    if (n == 0) {
        pid_t child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
        } else if (child_pid == 0) {
            // 子函数
            execvp(a[0], a);
            exit(0);
        } else {
            int stats;
            waitpid(child_pid, &stats, 0);
        }
    } else {
        // printf("dsfsd");
        number_ch[n] = (index) * 10;
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                number[i] = number_ch[i] / 10;
                for (int k = 0; k <= number_ch[i] / 10 - 1; k++) {
                    int len = strlen(a[k]);
                    ab[i][k] = (char *)malloc(sizeof(char) * len);
                    ab[i][k] = "\0";
                    // ab[i]
                    puts(a[k]);
                    // strcpy(ab[i][k], a[k]);
                    ab[i][k] = strdup(a[k]);
                    // printf("1ab[%d][%d]=%s\n", i, k, ab[i][k]);
                }
            } else {
                number[i] = number_ch[i] / 10 - number_ch[i - 1] / 10;
                int j = (number_ch[i - 1] / 10);
                for (; j < number_ch[i] / 10 - 1; j++) {
                    // printf("------------\n");
                    ab[i][j - (number_ch[i - 1]) / 10] =
                        (char *)malloc(sizeof(char) * 10);
                    memset(ab[i][j - (number_ch[i - 1]) / 10], '\0', 10);
                    strcpy(ab[i][j - (number_ch[i - 1]) / 10], a[j + 1]);
                }
            }
            // ab[i][j] = NULL;
            // printf("%d\n", i);
        }
        // printf("n=%d\n", n);
        for (int i = 0; i < n; i++) {
            ab[i][number[i]] = NULL;
            if (number_ch[i] % 10 == 1) {
                int nn = 0;
                while (i - nn != 0 && isSystemCommand(ab[i - nn][0]) == 0) {
                    nn++;
                }
                output1(ab[i + 1][0], ab[i - nn]);
                // free(abb);
            } else if (number_ch[i] % 10 == 3) { //>>
                printf("----------output2 >>\n");
                int nn = 0;
                while (i - nn != 0 && isSystemCommand(ab[i - nn][0]) == 0) {
                    nn++;
                }
                output2(ab[i + 1][0], ab[i - nn]);
            } else if (number_ch[i] % 10 == 2) {
                printf("----------output3 <\n");
                output3(ab[i + 1][0], ab[i],
                        number_ch[i + 1] / 10 - number_ch[i] / 10);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0;
                 j < (number_ch[i + 1] / 10) - (number_ch[i] / 10) - 2; j++) {
                free(ab[i][j]);
            }
        }
    }

    return 0;
}