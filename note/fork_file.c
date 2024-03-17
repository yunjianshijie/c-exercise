#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd, flags;
    char template[] = "/temp/testX";
    setbuf(stdout, NULL);
    fd = mkstemp(template);
    if (fd == -1) {
        exit(EXIT_FAILURE);
    }
    printf("File offset brfore fork():%lld\n",
           (long long)lseek(fd, 0, SEEK_CUR)); // 因为off_t返回类型太大了
    flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        exit(1);
    }
    printf("O_AA");
}