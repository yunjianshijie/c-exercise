#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // 创建管道
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // 创建子进程
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {       // 子进程
        close(pipefd[1]); // 关闭写入端

        // 从管道中读取数据
        read(pipefd[0], buffer, BUFFER_SIZE);
        printf("子进程接收到消息： %s\n", buffer);

        close(pipefd[0]);
    } else {              // 父进程
        close(pipefd[0]); // 关闭读取端

        char message[] = "Hello, Pipe!";

        // 向管道中写入数据
        write(pipefd[1], message, strlen(message) + 1);

        close(pipefd[1]);
    }

    return 0;
}