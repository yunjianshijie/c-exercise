#include "shell.h"

// int main() {
//     char *a[3];
//     a[0] = "ls";
//     a[1] = "-a";
//     a[2] = 0;
//     printf("sjfklse\n");
//     execvp("ls", a); // execvp()就像换了给脑子
//     printf("\njkdsfj\n");
// }

#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    return 0;
}