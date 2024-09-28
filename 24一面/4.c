// 位运算，补码，无符号
#include <stdio.h>
int main() {
    int a;
    unsigned b = 1u << 31;
    int c = 1u << 31;
    // printf("%u %d\n", b, c);
    if (c < 0 && b > 0) {
        printf("嘿嘿嘿\n");
    }
    if (b == (unsigned)c) {
        printf("哈哈哈\n");
    }
    scanf("%d", &a);
    while (b) {
        printf("%d", (a & b) ? 1 : 0);
        b >>= 1;
    }
    return 0;
}