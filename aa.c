//1欢迎来到linux 兴趣小组
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// int main(void)
// {
//     char *ptr0 = "Welcome to Xiyou Linux!";
//     char ptr1[23] = "Welcome to Xiyou Linux!";
//     if (ptr0 == ptr1)
//         printf("%d\n", printf("Hi Xiyou Linux Group 20"));
//     else if (strcmp(ptr0, ptr1))
//         printf("%d\n", printf("Hello, Linux Group - 2%d", printf("")));
//      int diff = ptr0 - ptr1;
//      printf("Pointer Difference: %d\n", diff);
// }

//char*ptr0为字符串常量指针，char ptr1[23]为字符串变量，地址不一样
//所以ptr0!=ptr1
//strcmp,函数，比较pro,ptr1,相等返回0
//因此最后只输出Pointer Difference: +地址差；

//2,一切都翻倍了吗
// int main() {
//     char arr[] = {'L', 'i', 'n', 'u', 'x','\0','!'},str[20];
//     short num = 520;    int num2 = 1314;
//     printf("%zu\t%zu\t%zu\n",sizeof(*&arr), sizeof(arr + 0), sizeof(num = num2 + 4));
//     printf("%d\n",sprintf(str, "0x%x", num) == num);
//     printf("%zu\t%zu\t%zu\n",strlen(&str[0]+1),strlen(arr + 0),strlen(&*(arr+1)+1));
// }

//sprintf()的返回值，返回被赋值字符串的长度（忽略'\0'),所以第二行为0
//sizeof()读取的多少字节，strlen()为多少
//赋值运算的返回

//3我的名字去那里了
// char* welcome1() {
//     char *a="Welcome to join the Xiyou Linux Group 2023";
//     return a;
// }
// char* welcome2() {
//     char b[20];
//     //请你填入自己的姓名
//     return b;
// }
// int main() {
//     char *a=welcome1();
//     char *b=welcome2();
//     printf("%s:",a);
//     printf("%s",b);
//     return 0;
// }
//输出Welcome to join the Xiyou Linux Group 2023 (null)
//所以我的名字去那里了呢？
//由于第二个函数中char b [20]为字符串变量，
//在函数结束时，内存释放，只传递了空指针
//所以输出null
//怎么看见自己名字呢？，一是将char b[20]设为静态变量，前加static
//二是用<stdlib.h>中malloc申请一个空间，内存同样不会被释放

//4奇怪的输出
// int main() {
//     char a = 64 & 127;  
//     char b = 64 ^ 127 ; 
//     char c = -64 >> 6; 
//     char ch = a+b-c;
//     printf("a = %d b = %d c = %d\n", a, b, c);
//     printf("ch = %d\n", ch);
// }
//输出为a =64 b = 63 c = -1
//ch = -128
//为运算 &与 ^亦或

//5.多看一看也不想看
// int func(int a, int b)
// {
//     if (!a)
//         return b;
//     return func((a & b) << 1, a ^ b);
// }

// int main()
// {
//     int a = 4, b = 9,c=-7;
//     printf("%d", func(a,func(b,c)));
// }

//为运算与递归完成加法

//6.自定义过滤

// typedef int (*Predicate)(int);//predicate 指针指向一个返回值为int (int)的函数
// int *filter(int *array, int length, Predicate predicate, int *resultLength)
// { int *filteredNumbers=(int *)malloc(sizeof(int)*length);
// for(int i=0 ;i<length ; i++){
//     if(predicate(array[i]))
//    filteredNumbers[i]= array[i] ;
// *resultLength=length;
// }

// return  filteredNumbers ;    
// }/*补全函数*/

// int isPositive(int num) {
//     return num > 0;
// }

// int main() {
//     int array[] = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
//     int length = sizeof(array) / sizeof(array[0]);//字符串长度（10）
//     int resultLength;
//     int *filteredNumbers = filter(array, length, isPositive, &resultLength);
//     for (int i = 0; i < resultLength; i++) {
//         printf("%d ", filteredNumbers[i]);
//     }
//     printf("\n");
//     free(filteredNumbers);
//     return 0;}

//7. 尊嘟假嘟 o.O
//#include<stdio.h>
// void func(int a, int b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// struct {
//     void (*O)(int, int);
// } o = {func};

// int main() {
//     int a = 1, b = 2, c;
//     o.O(a, b);
//     c = a - b;

//     if (c = 1)
//         printf("%c", 109 + printf("%c.", 78 + c));
//     else
//         printf("o.O");

//     return 0;}
//输出o.O,1, 形参，进入函数，之后互换没有用  
//2函数指针o是结构体的名字，O是个指针指向啥都不干函数。
//所以c==-1

//8指针要命
//int (*f1(int))(int*,int);
//f1 指针 指向 一个返回值为int (inr*,int)的函数..

//9凯撒密码
// #include<stdio.h>
// #include<string.h>
// int main(int argc, char* argv[],) {
//     printf("[%d] ", argc);
//     for (int i = 1; i < argc; i++) {
//         for (int j = 0; argv[i][j]; j++)
//             putchar(argv[i][j] - i);
//         putchar(i == argc - 1 ? '\n' : ' ');
//     }
//     return EXIT_SUCCESS;
// }//这次又对了，[哭哭]
//argc为传入main函数的参数个数,改变命令名 加上3个参数 及输出4(不知道怎么弄)
//

//#include<stdio.h>

//10,那个才是真正的我
// int main() {
//     char* message[] = {"SADLiNUX WELCOMeU",
//                  "NCOMEuHIDSABYMYLOVEXIYOU LINUX WELCOMETOXUPT", 
//                  "XiYOUCOME",
//                  "SIDWElDHGSWELYFDHSA"};
//     char** p_message[] = {message + 3, message + 2, message + 1, message};
//     char*** pp_message = p_message;
//     printf("0%.5s",**pp_message);
//     printf("1%.5s ", **++pp_message);
//     printf("2%.6s", *--*++pp_message + 3);
//     printf("3%.3s", *pp_message[-2] + 3);
//     printf("4%.5s\n", pp_message[-1][-1] + 1);
//     return 0;
// }//猜测、、内存连续。++pp


//11.克隆困境
 #include<string.h>
 #include<stdlib.h>
 #include<stdio.h>
// struct Student {
//     char *name;
//     int age;
// };

// void initializeStudent(struct Student *student, const char *name, int age) {
//     student->name = malloc(strlen(name) + 1);
//     strcpy(student->name, name);//strcpy将一个字符串复制到另一个地址空间中，
//     student->age = age;
// }

// int main() {
//     struct Student s1,s2;
//     //struct Student *ps1=&s1;
//     initializeStudent(&s1, "Tom", 18);
//     initializeStudent(&s2, "Jerry", 28);
//     s1= s2;
//     //s1.age=s2.age;
//     //strcpy(ps1->name,s2.name);
//     printf("s1的姓名: %s 年龄: %d\n", s1.name, s1.age);
//     printf("s2的姓名: %s 年龄: %d\n", s2.name, s2.age);
//     free(s1.name);
//     free(s2.name);
//     return 0;
// }
//s1=s2会出现free(); double free detected in tcache 2
//free()检测到双空闲空间，在执行程序的过程中对同一个空间释放了两遍
//为什么呢？由于s1=s2的操作是结构体浅拷贝，两个结构体公用一个内存空间
//解决方法，用strcp函数将第二个字符串放进第s1的地址。使其的空间独立。

//12,你好内存
//struct structure {
//     char foo;
//     union {
//         int integer;
//         char string[11];
//         void *pointer;
//     } node;
   
   
    
// };
// int main()
// {
//     int arr[] = {0x590ff23d, 0x2fbc5a4d, 0x636c6557,
//                 0x20656d6f, 0x58206f74, 0x20545055,
//                 0x6577202c, 0x6d6f636c, 0x6f742065,
//                 0x79695820, 0x4c20756f, 0x78756e69,
//                 0x6f724720, 0x5b207075, 0x33323032, 
//                 0x7825005d, 0x636c6557, 0x64fd6d1d};
//     printf("%s", ((struct structure *)arr)->node.string);
//     return 0;
//     //将arr强制转化成这struct structure的数组指向联合的string
// }

//输出 Welcome to XUPT , welcome to Xiyou Linux Group [2023]
//发现
//1将union 换成struct,没有输出Welc,
//2将结构体后面的数据删除没有影响，将arr内数据改变没有影响，但是删除了
//
//看不出来考点【哭哭】

//13宏

// #define RED_ARMY 1
// #define ENEMY 2
// #define GRASS "\n艹艹艹艹艹艹艹艹艹艹艹艹\n"
// #define FIRE_FIRE_FIRE_FIRE(star) starstarstarstarstar
// #define JINGGANG(x, y) printf(#x y);
// #define WIN(star, enemy) ((((star) + (star)) > enemy) ? 1 : 0)
// int main(){
//     int FLAG = ENEMY, star = 3;
//     if (FLAG == RED_ARMY)
//     {
//         puts("easy win!");
//         return 0;
//     }
//     JINGGANG(FIRE_FIRE_FIRE_FIRE(**), GRASS)
//     //printf()
//     puts("Turning point the Zunyi Conference\n...");
    
// #define FLAG RED_ARMY
//     if (WIN(++star, 8) && FLAG == 1)
//         printf("battle win");
//     else
//         printf("battle lose");
// }
//#字符串化，直接输出FIRE！
//++star自增且后输出，9>8,输出win!



