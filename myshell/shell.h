#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <pwd.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#define CLOSE "\001\033[0m\002"                   // 关闭所有属性
#define BLOD "\001\033[1m\002"                    // 强调、加粗、高亮
#define BEGIN(x, y) "\001\033[" #x ";" #y "m\002" // x: 背景，y: 前景
void home(char *a, char *home); // 判断是否在home/user里面,并改成~
char *printfs();                // 输入前面一串 返回输入字符串
char **scanfs(int *index, char *a); // 分割字符 index有多少给字符，返回输入
void cdfun(int index, char **a, char *history); // cd功能
void parent_code(int chilepid);
void sigint_handler(); // 屏蔽ctrl+c