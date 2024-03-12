#include "shell.h"

int main() {

    struct termios term; // 结构体储存终端中各种属性
    tcgetattr(0, &term); // 0为文件描述符，标准输入L
    term.c_cc[VEOF] = 0;
    tcsetattr(0, TCSANOW, &term);
    // 屏蔽ctrl+D
    while (1) {

        printfs();
        int index = 0;
        char **a = scanfs(&index);
        if (index == 0) {
            continue;
        }

        if (strcmp(a[0], "cd") == 0) {
            cdfun(index, a);
            continue;
        } else {
            printf("zsh: command not found: %s\n", a[1]);
        }
        int h = 0;
        for (int i = 0; i < index; i++) {
            if (strcpy(a[i], ">") == 0 || strcpy(a[i], "<") == 0 ||
                strcpy(a[i], ">>") || strcpy(a[i], "<<")) {
                h = 1;
            }
        }
        if (h == 1) {
            printf("此时逆袭\n");
        } else {
            pid_t child_pid;
            child_pid = fork();
            if (child_pid == -1) {
                perror("fork");
            } else if (child_pid ==) {
                e
            }
        }

        fflush(stdin);
        free(a);
    }

    return 0;
}

void home(char *a, char *home) {
    int lenhome = strlen(home);
    int len = strlen(a);
    a[0] = '~';
    for (int i = 1; i < len - lenhome + 1; i++) {
        a[i] = a[i + lenhome - 1];
    }
    a[len - lenhome + 1] = '\0';
}

void printfs() {
    // char *dfh = getenv("HOME");
    // printf("%s", dfh);
    char *username = getlogin();
    printf("  \033[0;36m%s\033[0m @", username); // 用户名
    FILE *file = fopen("/proc/sys/kernel/hostname", "r");
    if (file == NULL) {
        return;
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
    printf("\n\033[1;31m$\033[0m ");
}

char **scanfs(int *index) {
    char **str = (char **)malloc(sizeof(char *) * 100);
    char a[1000];
    char ch;
    int i = 0;
    // printf("ksl\n");
    while ((ch = getchar()) != '\n') {
        a[i++] = ch;
        // printf("%d  ", i);
    }
    // printf("a======%s\n", a);
    a[i] = '\0';
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

void cdfun(int index, char **a) {
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
