## 负与正相隔 int 的爱情

> - 题目问题

```c
#include <stdio.h>
int main() {
    int a;
    unsigned b = 1u << 31;
    int c = 1u << 31;
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
```

> - 问题：本段代码打印了什么？为什么会出现这个结果？

---

### 出题人、知识点

| 出题人 | 知识点          |
| ------ | --------------- |
| 代凌嘉 | 补码 无符号整数 |

---

### 现场要问的问题列表

1. 最后出现的数字是什么？会出现这个结果，循环里面是什么？
2. 10 进制转化成 2 进制还有那种方式？
3. 为什么`哈哈哈`和`嘿嘿嘿`都会被打印？讲讲`补码`和`原码`。

---

### 答案列表

1. 输入数字的二进制文件。最后输出的数字是整数 a 的二进制表示，按位从最高位到最低位打印。循环中的逻辑是通过位运算逐位检查 a 的二进制值，并打印出每一位的结果。如果你还有其他问题或需要进一步的解释，请告诉我！最后输出的数字是整数 a 的二进制表示，按位从最高位到最低位打印。循环中的逻辑是通过位运算逐位检查 a 的二进制值，并打印出每一位的结果。如果你还有其他问题或需要进一步的解释，请告诉我！
2. 记录余数的方式。
3. unsigned b 和 int c：b 是无符号整数，而 c 是有符号整数。由于左移的结果超出了有符号整数的范围，c 将被视为负数。由于 unsigned b 和 int c 的源码相同

---

### 评价标准

- **标准 1**: 知道了解补码，原码以及无符号数。
- **标准 2**: 说出结果是什么，知道最后结果的原因。
- **标准 3**: 答案错误，理解错误或者不知道。
