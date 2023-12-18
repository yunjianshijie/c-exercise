// 实现 ls 的 -a、-l、-R、-t、-r、-i、-s 参数，并允许这些参数任意组合

// ls

#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

struct sb {
    int alloc;
    char str[257];
    struct sb* hh;
};

enum Color {
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    BROWN = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    GREY = 37,
    LRED = 41,
    LGREEN = 42,
    YELLOW = 43,
    LBLUE = 44,
    LMAGENTA = 45,
    LCYAN = 46,
    WHITE = 47,
};

// 函数声明
void help(void);                  // 输出help 内容
void yanse(char* aar, int i);     // 输出加粗有颜色字体
int mode(char* pathname);         // 判断文件类型
char* quanxian(struct stat* sb);  // 输出权限
char* path();
int zhongji(char* path);  // 求总内存
int zimu[56] = {0};

// 输出help
void help(void) {
    int fd;
    if ((fd = open("help", O_RDONLY)) == -1) {
        exit(EXIT_FAILURE);
    }
    char ch[101];
    int count = 0;
    while ((count = read(fd, ch, 100)) == 100) {
        ch[100] = '\0';
        printf("%s", ch);
    }
    read(fd, ch, 100);
    printf("%s", ch);

    printf("\n");
    // ssize_t pread(int fd, void *buf ,size_t count ,off_t offset);
}

// 改变字体颜色
void yanse(char* arr, int i) {
    if (i == 34)  // 蓝色
        printf("\033[01;34m%s\033[0m", arr);
    if (i == 32)  // 绿色
        printf("\033[01;32m%s\033[0m", arr);
    if (i == 31)
        printf("\031[01;32m%s\031[0m", arr);
}

// 判断文件类型
int mode(char* pathname) {
    struct stat* sb = (struct stat*)malloc(sizeof(struct stat));

    if (stat(pathname, sb) == 0) {
        switch (sb->st_mode & __S_IFMT) {
            case __S_IFREG:
                if (sb->st_mode & S_IXUSR) {
                    free(sb);
                    return 0;
                }  // 可执行文件
                free(sb);
                return 1;
                break;  // 常规文件
            case __S_IFDIR:
                free(sb);
                return 2;
                break;  // 目录
            case __S_IFCHR:
                free(sb);
                return 3;
                break;  // 字符设备
            case __S_IFBLK:
                free(sb);
                return 4;
                break;  // 块设备
            case __S_IFIFO:
                free(sb);
                return 5;
                break;  // FIFO 或管道
            case __S_IFSOCK:
                free(sb);
                return 6;
                break;  // 套接字
            case __S_IFLNK:
                free(sb);
                return 7;
                break;  // 符号链接
            default:
                free(sb);
                return 8;  // 不知道的类型
        };
    } else {
        free(sb);
        return -1;
    }
}

char mode2(int i) {
    if (i == 1 || i == 0)
        return '-';
    if (i == 2)
        return 'd';
    if (i == 3)
        return 'c';
    if (i == 4)
        return 'b';
    if (i == 5)
        return 'p';
    if (i == 6)
        return 's';
    if (i == 7)
        return '|';
    return '*';
}

char* quanxian(struct stat* sb)  // 输出权限记得free
{
    char* a = (char*)malloc(sizeof(char) * 10);
    a[9] = '\0';
    if (sb->st_mode & S_IRUSR) {
        a[0] = 'r';
    } else
        a[0] = '-';
    if (sb->st_mode & S_IWUSR) {
        a[1] = 'w';
    } else
        a[1] = '-';
    if (sb->st_mode & S_IXUSR) {
        a[2] = 'x';
    } else
        a[2] = '-';
    if (sb->st_mode & S_IRGRP) {
        a[3] = 'r';
    } else
        a[3] = '-';
    if (sb->st_mode & S_IWGRP) {
        a[4] = 'w';
    } else
        a[4] = '-';
    if (sb->st_mode & S_IXGRP) {
        a[5] = 'x';
    } else
        a[5] = '-';
    if (sb->st_mode & S_IROTH) {
        a[6] = 'r';
    } else
        a[6] = '-';
    if (sb->st_mode & S_IWOTH) {
        a[7] = 'w';
    } else
        a[7] = '-';
    if (sb->st_mode & S_IXOTH) {
        a[8] = 'x';
    } else
        a[8] = '-';
    return a;
}

// void cmp(cah)

void ls_a(char* agrv) {
    DIR* dir;
    struct dirent* direntd;
    dir = opendir(agrv);
    if (dir == NULL) {
        if (open(agrv, O_RDONLY) == -1) {
            perror("open1");
        } else {
            printf("%s\n", agrv);
            return;
        }
    } else {
        direntd = readdir(dir);
        while (direntd != NULL) {
            if (mode(direntd->d_name) == 2) {
                yanse(direntd->d_name, 34);
                printf("   ");
            } else if (mode(direntd->d_name) == 0) {
                yanse(direntd->d_name, 32);
                printf("   ");
            } else
                printf("%s   ", direntd->d_name);
            direntd = readdir(dir);
        }
    }
    printf("\n");
}

// //
void ls(char* agrv) {
    DIR* dir;
    struct dirent* direntd;
    dir = opendir(agrv);
    if (dir == NULL) {
        if (open(agrv, O_RDONLY) == -1) {
            perror("open1");
        } else {
            printf("%s\n", agrv);
            return;
        }
    } else {
        direntd = readdir(dir);
        while (direntd != NULL) {
            if (zimu['a' - 'A'] = 1) {
                if ((strcmp(direntd->d_name, ".") == 0 &&
                     strcmp(direntd->d_name, "..") == 0))
                    continue;
            }

            struct stat sb;
            char pathname[100];
            strcpy(pathname, agrv);
            strcat(pathname, "/");
            strcat(pathname, direntd->d_name);
            stat(pathname, &sb);

            if (zimu['i' - 'A'] == 1) {
                printf("%4d    ", sb.st_ino);
            }

            // 输出i节点
            if (zimu['l' - 'A'] == 1) {
                printf("%c", mode2(mode(pathname)));
                printf("%s ", quanxian(&sb));
                printf("%d ", sb.st_nlink);
                struct passwd* pwd = getpwuid(sb.st_uid);
                printf("%10s ", pwd->pw_name);
                struct group* grp = getgrgid(sb.st_gid);
                printf("%10s ", grp->gr_name);
                // printf("%4ld ",sb.st_uid);
                // printf("%4ld ",(long)sb.st_gid);
                printf("%7d ", sb.st_size);

                time_t mt = sb.st_mtime;

                printf("%12s", ctime(&mt));
                printf("\b%%  ");
            }  // l参数

            if (mode(direntd->d_name) == 2) {
                yanse(direntd->d_name, 34);
                printf("   ");
            } else if (mode(direntd->d_name) == 0) {
                yanse(direntd->d_name, 32);
                printf("   ");
            } else
                printf("%s   ", direntd->d_name);
            direntd = readdir(dir);
            printf("\n");
        }
    }
    printf("\n");
}

void ls_R(char* agrv) {
    static int h3 = 0;
    int h = mode(agrv);
    DIR* dir = opendir(agrv);
    struct dirent* direntd;
    if (h3 == 0) {
        printf(".:\n");
    }
    ls(agrv);
    h3++;
    printf("\n");
    while ((direntd = readdir(dir)) != NULL) {
        char path2[1000];
        strcpy(path2, agrv);
        strcat(path2, "/");
        strcat(path2, direntd->d_name);
        if (strcmp(direntd->d_name, ".") != 0 &&
            strcmp(direntd->d_name, "..") != 0 && mode(path2) == 2) {
            printf("%s/%s:\n", agrv, direntd->d_name);
            // 把agrv/往后推
            char path[1000];
            strcpy(path, agrv);
            strcat(path, "/");
            strcat(path, direntd->d_name);

            if (mode(path) == 2) {
                ls_R(path);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // if (agrc == 2 && !strcmp(agrv[1], "-a"))
    // {
    //     ls_a(".");
    // }
    // if (agrc == 1)
    // {
    //     ls(".");
    // }
    // if (agrc > 1 && !strcmp(agrv[1], "--help"))
    // {
    //     help();
    // }

    if (argc == 1) {
        ls(".");
        return 0;
    }
    char mulu[100][256];
    int count = 0;
    int count2 = 0;
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-') {
                for (int j = 1; j < strlen(argv[i]); j++) {
                    if (argv[i][j] == 'r' || argv[i][j] == 'l' ||
                        argv[i][j] == 'R' || argv[i][j] == 't' ||
                        argv[i][j] == 'a' || argv[i][j] == 'i' ||
                        argv[i][j] == 's') {
                        zimu[argv[i][j] - 'A'] = 1;
                        count++;
                    } else {
                        printf(
                            "ls: 请尝试执行 \"ls --help\" 来获取更多信息。\n");
                        return 0;
                    }
                }
            } else {
                int h = mode(argv[i]);
                if (h == -1) {
                    printf("ls: 无法访问 '%s': 没有那个文件或目录\n", argv[i]);
                } else {
                    strcpy(mulu[count2], argv[i]);
                    count2++;
                }
            }
        }

        // 纪录命令行
        if (count2 == 0) {
            ls(".");
        } else {
            for (int i = 0; i < count2; i++) {
                printf("%s:\n", mulu[i]);
                if (zimu['R' - 'A'] == 1) {
                    ls_R(mulu[i]);
                    continue;
                }
                ls(mulu[i]);
            }
        }
    }
}
