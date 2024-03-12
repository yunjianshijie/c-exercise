#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <pwd.h>
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
void home(char *a, char *home);  // 判断是否在home/user里面,并改成~/
void printfs();                  // 输入前面一串
char **scanfs(int *index);       // index有多少给字符，返回输入
void cdfun(int index, char **a); // cd功能