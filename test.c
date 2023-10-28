// #include<stdio.h>
// int main(){
// int n;
// scanf("%d",&n);
// int sum=0;
// int sum2=0;
// for(int i=1 ;i<=n ;i++){
// sum+=i;
// sum2+=sum;

// }
// if(n>0) printf("%d",sum2);
// else printf("Error!");
// return 0;
// } 
//#include<stdio.h>
// int main(){
// int n;
// scanf("%d",&n);
// int sum=0;
// for(int i=1 ;i<=n ;i++){
// sum=sum*2+i;
// }
// if(n>0) printf("%d",sum);
// else printf("Error!");
// return 0;
//}// #include<stdio.h>
// int main(){
// printf("??????");
// return 0;

// }
// #include <stdio.h>

// int main() {
//     int number;
//     for (int i = 32; i < 100; i++) {
//         number = i * i;
//         int digit1 = (number / 1000) % 10;
//         int digit2 = (number / 100) % 10;
//         int digit3 = (number / 10) % 10;
//         int digit4 = number % 10;
        
//         if (digit1 == digit2 && digit3 == digit4) {
//             printf("The number is %d", number);
//             break;
//         }
//     }
    
//     return 0;
// }


// #include <stdio.h>

// int main() {
//     int men, women, children;

//     // 遍历男、女、小孩的人数
//     for (men = 1; men <= 36; men++) {
//         for (women = 1; women <= 36; women++) {
//             for (children = 1; children <= 36; children+=2) {
//                 // 判断是否满足条件
//                 if (men + women + children == 36 && men * 4 + women * 3 + children / 2 == 36) {
//                     printf("男%d人,女%d人,小孩%d人\n", men, women, children);
//                 }
//             }
//         }
//     }

//     return 0;
// }