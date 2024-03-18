#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pid_t pid;

    // 创建管道
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {                    // 子进程
        close(pipefd[1]);              // 关闭写入端
        dup2(pipefd[0], STDIN_FILENO); // 将标准输入重定向到管道读取端
        execlp("wc", NULL); // 在子进程中执行 wc 命令统计单词数
    } else {                // 父进程
        close(pipefd[0]);   // 关闭读取端
        dup2(pipefd[1], STDOUT_FILENO); // 将标准输出重定向到管道写入端
        execlp("ls", "ls", NULL); // 在父进程中执行 ls 命令列出当前目录文件
    }

    return 0;
}