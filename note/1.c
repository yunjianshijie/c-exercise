#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);

        // 移除末尾的换行符
        command[strcspn(command, "\n")] = 0;

        // 分割命令和参数
        char *args[MAX_ARGS];
        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // 创建子进程执行命令
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // 子进程执行命令
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // 等待子进程执行完毶
            wait(NULL);
        }
    }
    return 0;
}