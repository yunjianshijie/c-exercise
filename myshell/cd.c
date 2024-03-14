#include "shell.h"
void home(char *a, char *home) {
    int lenhome = strlen(home);
    int len = strlen(a);
    a[0] = '~';
    for (int i = 1; i < len - lenhome + 1; i++) {
        a[i] = a[i + lenhome - 1];
    }
    a[len - lenhome + 1] = '\0';
}

int main() {
    char new_directory[256];
    char cwd[1024];
    struct passwd *pw = getpwuid(getuid());
    const char *home_dir = pw->pw_dir; // 获取用户目录
    while (1) {

        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            if (strcmp(pw->pw_dir, cwd) <= 0) {
                home(cwd, pw->pw_dir);
            }
            printf("in %s ", cwd);
        }
        scanf("%s", new_directory);
        if (chdir(new_directory) == 0) {
            printf("Changed directory to: %s\n", new_directory);
        } else {
            perror("chdir");
        }
    }
    return 0;
}
