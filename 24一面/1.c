// 生命周期

#include <stdio.h>
int xx = 0;
void x_X(int xx) {
    printf("xx=%d\n", --xx);
    xx = 520;
}
void X_x(int* xx) {
    printf("xx=%d\n", *xx);
    *xx = 1314;
}
int main() {
    printf("xx=%d\n", xx);  // 0
    int xx = 666;
    printf("xx=%d\n", xx++);  // 666
    do {
        int xx = 114;
        printf("xx=%d\n", ++xx);  // 115
        x_X(xx);                  // 115 ,进去114
    } while (0);
    printf("xx=%d\n", xx - 1);  // 667-1
    X_x(&xx);                   // 667
    printf("xx=%d\n", xx);      // 1314
    return 0;
}
