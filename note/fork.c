#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static int idata = 111;
int main() {
    int istack = 222;
    pid_t childPid;
    switch (childPid = fork()) {
    case -1:
        exit(1);
    case 0:
        idata *= 3;
        istack *= 3;
        break;
    default:
        // sleep(3);
        break;
    }
    printf("PID=%ld %s idata=%d istack=%d\n", (long)getpid(),
           (childPid == 0) ? "(child)" : "(parent)", idata, istack);
    exit(1);
}
