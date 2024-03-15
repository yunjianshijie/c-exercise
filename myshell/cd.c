// #include "shell.h"
// void home(char *a, char *home) {
//     int lenhome = strlen(home);
//     int len = strlen(a);
//     a[0] = '~';
//     for (int i = 1; i < len - lenhome + 1; i++) {
//         a[i] = a[i + lenhome - 1];
//     }
//     a[len - lenhome + 1] = '\0';
// }

// int main() {
//     char new_directory[256];
//     char cwd[1024];
//     struct passwd *pw = getpwuid(getuid());
//     const char *home_dir = pw->pw_dir; // 获取用户目录
//     while (1) {

//         if (getcwd(cwd, sizeof(cwd)) != NULL) {
//             if (strcmp(pw->pw_dir, cwd) <= 0) {
//                 home(cwd, pw->pw_dir);
//             }
//             printf("in %s ", cwd);
//         }
//         scanf("%s", new_directory);
//         if (chdir(new_directory) == 0) {
//             printf("Changed directory to: %s\n", new_directory);
//         } else {
//             perror("chdir");
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    // 打开要重定向的文件或设备
    FILE *file = fopen("2", "w");

    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // 将标准输出重定向到文件
    int fd = fileno(file);
    dup2(fd, STDOUT_FILENO);

    // 输出内容将会被重定向到 output.txt 文件中
    printf("Hello, redirect!\n");
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
    } else if (child_pid == 0) {
        char a[2][12];
        strcpy(a[0], "ls");
        char *b[] = {"ls", NULL};
        execvp("ls", b);
        exit(1);
    } else {
        int wait_rv;
        int child_stats;
        wait_rv = wait(&child_stats);
    }

    // 关闭文件
    fclose(file);
    fork();
    return 0;
}