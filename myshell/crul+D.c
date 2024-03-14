// // #include <readline/history.h>
// // #include <readline/readline.h>
// #include <stdio.h>
// #include <stdlib.h>

// void custom_eof() { printf("\nCtrl+D 被禁用\n"); }

// int main() {
//     // 绑定 Ctrl+D 到自定义函数
//     rl_bind_key(4, custom_eof);

//     char *input;
//     while (1) {
//         input = readline(">> ");
//         if (!input) {
//             // 如果输入为空，则跳出循环
//             break;
//         }
//         // 处理输入
//         printf("输入: %s\n", input);
//         add_history(input);
//         free(input);
//     }

//     return 0;
// }