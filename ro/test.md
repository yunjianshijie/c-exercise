@[TOC](2021-2023西邮linux兴趣小组纳新题)
# 

# 2023
## 0.鼠鼠我啊，要被祸害了
有 1000 瓶水，其中有一瓶有毒，l小白鼠只要尝一点带毒的水，24 小时后就会准时死亡。
至少要多少只小白鼠才能在 24 小时内鉴别出哪瓶水有毒？

将1000瓶水的标签转化会二进制，也就是0000000000到1111101000。然后将第一位为1的水混合在一起喂给小鼠，如果小鼠死亡则毒水二进制的一位为1，以此类推10次便可以得到毒水二进制编号，转化为10进制即可。

## 1.先预测一下~
按照函数要求输入自己的姓名试试~
~~~c
char *welcome() {
 // 请你返回自己的姓名
}
int main(void) {
 char *a = welcome();
 printf("Hi, 我相信 %s 可以面试成功!\n", a);
 return 0; }
~~~
如果是在函数中填写//char a[20]="yunjian";  return a;   最后会输出 我相信(null)可以面试成功！
我的名字去哪里了呢?由于a为字符串数组，存储在栈中，在函数结束后，栈的内存释放，导致a的地址指向了(null)成为空指针。
所以可以有两种做法，一是在 char前加入 static 关键词 ，使成为静态变量延长其生命周期。 
二是 ，申请动态规格，，char* a=(char*)malloc(sizeof(char)*7);(只是因为yunjian为7个字符长度)
strcpy(a,"yunjian"); 或者 a="yunjian";

当然也可以绕过不使用变量，char* a="yunjian";
或者直接返回字符串 return "yunjian";

## 2.欢迎来到 Linux 兴趣小组
有趣的输出，为什么会这样子呢~
~~~c
int main(void) {
 char *ptr0 = "Welcome to Xiyou Linux!";
 char ptr1[] = "Welcome to Xiyou Linux!";
 if (*ptr0 == *ptr1) {
 printf("%d\n", printf("Hello, Linux Group - 2%d", printf("")));
 }
 int diff = ptr0 - ptr1;
 printf("Pointer Difference: %d\n", diff);
}
~~~
输出：

> Hello, Linux Group - 2023
Pointer Difference: -2077387488 //（这会是个随机值）


1,printf()函数是从右往左读的，2，printf()函数的返回值为打印的字符串长度（包括空格）所以会打印出Hello, Linux Group - 2023
3，*ptr0为字符串常量，存放在静态区域，而ptr1[]是字符串变量，存放在栈中，地址当然不一样了,,所以地址有差值。

## 3.一切都翻倍了吗
① 请尝试解释一下程序的输出。
② 请谈谈对 sizeof()和 strlen()的理解吧。
③ 什么是 sprintf()，它的参数以及返回值又是什么呢？
~~~c
int main(void) {
 char arr[] = {'L', 'i', 'n', 'u', 'x', '\0', '!'}, str[20];
 short num = 520;
 int num2 = 1314;
 printf("%zu\t%zu\t%zu\n", sizeof(*&arr), sizeof(arr + 0),
 sizeof(num = num2 + 4));
 printf("%d\n", sprintf(str, "0x%x", num) == num);
 printf("%zu\t%zu\n", strlen(&str[0] + 1), strlen(arr + 0));
}
~~~
输出：

> 7       8       2
0
4       5

②sizeof()（为运算符）为字节数（计算时连带'\0'),strlen()(为string.h的函数) 计算char*字符串的长度（读到'\0'结束）
③sprintf() 为string.h的函数，参数为 sprintf( char *,const char *,(传入值可为int double char 等等));
作用将第二给参数打印进第一个参数中(char *)（不打印进终端）;
返回值与printf()的返回值类似，为打印的长度，

## 4.奇怪的输出
程序的输出结果是什么？解释一下为什么出现该结果吧~
~~~c
int main(void) {
 char a = 64 & 127;//100000 &111111==100000==64
 char b = 64 ^ 127;//100000 &111111==011111==63
 char c = -64 >> 6;//-100000 >> 6=-000001==-1
 char ch = a + b - c;//64+63-(-1)==128;
 printf("a = %d b = %d c = %d\n", a, b, c);
 printf("ch = %d\n", ch);
}
~~~
位运算，如注释
## 5.乍一看就不想看的函数
“人们常说互联网凛冬已至，要提高自己的竞争力，可我怎么卷都卷不过别人，只好用一些奇技淫
巧让我的代码变得高深莫测。”
这个 func()函数的功能是什么？是如何实现的？
~~~c
int func(int a, int b) {
 if (!a) return b;
 return func((a & b) << 1, a ^ b);
}
int main(void) {
 int a = 4, b = 9, c = -7;
 printf("%d\n", func(a, func(b, c)));
}
~~~
功能：实现两数相加
实现：由于位运算a+b=(a^b)+((a&b)<<1);(亦或运算相当于相加不进位，而与运算再右移相当于进位）
使这个等式递归，到进位(a&b)<<1==0时，便不进位了，a&b=a+b;

## 6.自定义过滤
请实现 filter()函数：过滤满足条件的数组元素。
提示：使用函数指针作为函数参数并且你需要为新数组分配空间。

```c
typedef int (*Predicate)(int);
int *filter(int *array, int length, Predicate predicate,
 int *resultLength); /*补全函数*/

int isPositive(int num)
 { return num > 0; }

int main(void) {
 int array[] = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
 int length = sizeof(array) / sizeof(array[0]);
 int resultLength;
 int *filteredNumbers = filter(array, length, isPositive,
 &resultLength);
 for (int i = 0; i < resultLength; i++) {
 printf("%d ", filteredNumbers[i]);
 }
 printf("\n");
 free(filteredNumbers);
 return 0; }`
```
不知道对于否
 
//
```c
typedef int (*Predicate)(int);//predicate 指针指向一个返回值为int (int)的函数
int *filter(int *array, int length, Predicate predicate, int *resultLength)
{ int *filteredNumbers=(int *)malloc(sizeof(int)*length);
int j;
for(int i=0 ,j=0;i<length ; i++){

    if(predicate(array[i])){
   filteredNumbers[j]= array[i] ;
   j++;
   }
*resultLength=j;
}

return  filteredNumbers ;    
}

```


## 7.静...态...
① 如何理解关键字 static？ 
② static 与变量结合后有什么作用？
③ static 与函数结合后有什么作用？
④ static 与指针结合后有什么作用？
⑤ static 如何影响内存分配？

① 关键词，静态
② 与局部变量的结合，改变变量的生命周期（不改变作用域），与全局变量结合改变其作用域（使其属性从外部链接变为内部链接）。
③ 与全局变量差不多，使其属性从外部链接变为内部链接，使其它文件无法使用该函数。
④ 指针的指向的地方是不变的（如果不重新赋值），其指向的东西可以变。
⑤ 将局部变量从栈区编入静态区（和全局变量放一起了）


## 8.救命！指针！
数组指针是什么？指针数组是什么？函数指针呢？用自己的话说出来更好哦，下面数据类
型的含义都是什么呢？
~~~c
int (*p)[10];//一个数组指针。指针指向一个10个int 元素的数组
const int* p[10];//一个指针数组，数组里有10个类型为指向const int的指针元素
int (*f1(int))(int*, int);//函数指针，指向一个返回值类型为（返回值类型为int,形参为(int*,int )的函数）的函数。
~~~

## 9.咋不循环了
程序直接运行，输出的内容是什么意思？
~~~c
int main(int argc, char* argv[]) {
 printf("[%d]\n", argc);
 while (argc) {
 ++argc;
 }
 int i = -1, j = argc, k = 1;
 i++ && j++ || k++;
 printf("i = %d, j = %d, k = %d\n", i, j, k);
 return EXIT_SUCCESS; }
~~~

argc（初始为一）为int 类型，  一直循环至2^31之后超出界限变为0之后，循环结束。


## 10.到底是不是 TWO
~~~c
#define CAL(a) a * a * a
#define MAGIC_CAL(a, b) CAL(a) + CAL(b)
int main(void) {
 int nums = 1;
 if(16 / CAL(2) == 2)//if(16/2*2*2 ==2)   16/2*2*2等于32;（考点：宏定义单纯的文本替换，不会进行运算）
  {
 printf("I'm TWO(ﾉ>ω<)ﾉ\n");
 } else {
 int nums = MAGIC_CAL(++nums, 2);
 //赋值从右往左，nums=++nums*++nums*++nums+8;

 //（由于乘法两数相乘，同时进行，所以如果nums==1,则答案会是3*3*4+8==32）
 //算是局部函数，将nums全局变量覆盖掉了（这个是最后输出为1的原因）
 //为定义行为
 }
 printf("%d\n", nums);//1
}
~~~

## 11.克隆困境
试着运行一下程序，为什么会出现这样的结果？
直接将 s2 赋值给 s1 会出现哪些问题，应该如何解决？请写出相应代码。
~~~c
struct Student {
 char *name;
 int age;
};
void initializeStudent(struct Student *student, const char *name,
 int age) {
 student->name = (char *)malloc(strlen(name) + 1);
 strcpy(student->name, name);
 student->age = age; }
int main(void) {
 struct Student s1, s2;
 initializeStudent(&s1, "Tom", 18);
 initializeStudent(&s2, "Jerry", 28);
 s1 = s2;
 printf("s1 的姓名: %s 年龄: %d\n", s1.name, s1.age);
 printf("s2 的姓名: %s 年龄: %d\n", s2.name, s2.age);
 free(s1.name);
 free(s2.name);
 return 0; }
~~~
s1=s2会出现free(); double free detected in tcache 2
free()检测到双空闲空间，在执行程序的过程中对同一个空间释放了两遍
为什么呢？由于s1=s2的操作是结构体浅拷贝，两个结构体公用一个内存空间
解决方法，用strcp函数将第二个字符串放进第s1的地址。使其的空间独立。

## 12.你好，我是内存
作为一名合格的 C-Coder，一定对内存很敏感吧~来尝试理解这个程序吧！
~~~c
struct structure {
 int foo;
 union {
 int integer;
 char string[11];
 void *pointer;
 } node;
 short bar;
 long long baz;
 int array[7];
};
int main(void) {
 int arr[] = {0x590ff23c, 0x2fbc5a4d, 0x636c6557, 0x20656d6f,
 0x58206f74, 0x20545055, 0x6577202c, 0x6d6f636c,
 0x6f742065, 0x79695820, 0x4c20756f, 0x78756e69,
 0x6f724720, 0x5b207075, 0x33323032, 0x7825005d,
 0x636c6557, 0x64fd6d1d};
 printf("%s\n", ((struct structure *)arr)->node.string);
}
~~~

大小端：


## 13.GNU/Linux (选做)
注：嘿！你或许对 Linux 命令不是很熟悉，甚至你没听说过 Linux。但别担心，这是选做题，了解
Linux 是加分项，但不了解也不扣分哦！
你知道 cd 命令的用法与 / . ~ 这些符号的含义吗？
请问你还懂得哪些与 GNU/Linux 相关的知识呢~

cd / 回到根目录
cd ~进入用户主目录
cd ! 将上个命令参数做为cd参数
cd .. 返回两层
cd .././..

# 2022

## 0. 我的计算器坏了？！

 2^10 = 1024对应于十进制的4位，那么2^10000对应于十进制的多少位呢?

取2^1000的10的对数，使其向上取整

## 1. printf还能这么玩？
尝试着解释程序的输出。

```c
int main(void) {
    if ((3 + 2 < 2) > (3 + 2 > 2))//(5<2)>(5>2)==0>1==0 所以进入else
        printf("Welcome to Xiyou Linux Group\n");
    else
        printf("%d\n", printf("Xiyou Linux Group - 2%d", printf("")));
}
```

printf()函数从右向左数，且其返回值为字符串长度（包括空格）
所以先打印printf("");其返回为0，再打印printf("Xiyou Linux Group - 20);其返回值为22，再打印printf("22\n"):
最后结果为Xiyou Linux Group - 2022

## 2. 你好你好你好呀！
程序的输出有点奇怪，请尝试解释一下程序的输出吧。
请谈谈对sizeof()及strlen()的理解吧。
~~~c
int main(void) {
    char p0[] = "Hello,Linux";
    char *p1 = "Hello,Linux";
    char p2[11] = "Hello,Linux";
    printf("p0 == p1: %d, strcmp(p0, p2): %d\n", p0 == p1, strcmp(p0, p2));
    printf("sizeof(p0): %zu, sizeof(p1): %zu, sizeof(*p2): %zu\n",
           sizeof(p0), sizeof(p1), sizeof(*p2));
    printf("strlen(p0): %zu, strlen(p1): %zu\n", strlen(p0), strlen(p1));
}
~~~
输出：

> p0 == p1: 0, strcmp(p0, p2): -1
sizeof(p0): 12, sizeof(p1): 8, sizeof(*p2): 1
strlen(p0): 11, strlen(p1): 11
 
1，*ptr0为字符串常量，存放在静态区域，而ptr1[]是字符串变量，存放在栈中，地址当然不一样了，所以p0==p1的值为0。
2，strcmp为比较函数， int strcmp (const char* str1 ,const char* str2 );   比较两个字符串的大小，按ASCLL码比较 ，str1==str2 返回 0；
str1<str2,返回负数，str1>str2,则返回正数。
3，sizeof()及strlen()在2023的第2题。

## 3. 换个变量名不行吗？
请结合本题，分别谈谈你对C语言中「全局变量」和「局部变量」的「生命周期」理解。
~~~c
int a = 3;//全局变量 记a1;
void test() {
    int a = 1;//局部变量，记a2，其掩盖全局变量a1
    a += 1;//a2==2;
    {
        int a = a + 1;//a3,掩盖a2,a1
        printf("a = %d\n", a);//此时a未定义，a为随机值
    }
    printf("a = %d\n", a);//a2,输出2
}
int main(void) {
    test();
    printf("a= %d\n", a);//a1=3,此时a2,a3已经释放
}
~~~
输出：

> a = 1(随机值)
a = 2
a= 3

## 4. 内存对不齐
union与struct各有什么特点呢，你了解他们的内存分配模式吗。
~~~c
typedef union {
    long l;
    int i[5];//5*4
    char c;
} UNION;
typedef struct {
    int like;//4
    UNION coin;//20
    double collect;//8
} STRUCT;
int main(void) {
    printf("sizeof (UNION) = %zu\n", sizeof(UNION)); 
    printf("sizeof (STRUCT) = %zu\n", sizeof(STRUCT));
}
~~~
输出：
> sizeof (UNION) = 20
sizeof (STRUCT) = 32

union  联合体的内存为最大的数据 为int i[5]，使用时诺将赋值一个元素，上一个元素将覆盖,而 struct 结构体的内存为 各排列内存之和。
内存对齐为最大（数据类型）的字节数，其的内存分配为最大字节的倍数；（其的可能地址不是放在一起的，中间有空间隔）
（因此若需最小内存，将内存相近的数放相近，使空空间减少）
## 5.Bitwise
请使用纸笔推导出程序的输出结果。
请谈谈你对位运算的理解。
~~~c
int main(void) {
    unsigned char a = 4 | 7;//100 |111 = 111
    a <<= 3; // a=a*8;
    unsigned char b = 5 & 7;//101 & 111 = 101
    b >>= 3; //b=0
    unsigned char c = 6 ^ 7;//0110 ^ 0111 = 1
    c = ~c;//取反 
    unsigned short d = (a ^ c) << 3;
    signed char e = -63;//1100
    e <<= 2;
    printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, (char)d);
    printf("e: %#x\n", e);//16进制输出
}
~~~
输出：
> a: 56, b: 0, c: 254, d: 48
e: 0x4

## 6. 英译汉
请说说下面数据类型的含义，谈谈const的作用。

char *const p。//常数变量指针，其内存地址不改变
char const *p。//与3一样指向的字符变量为常量，不改变了
const char *p。//

## 7. 汉译英
请用变量p给出下面的定义:

含有10个指向int的指针的数组。//int *a[10]
指向含有10个int数组的指针。//int(*a[10])
含有3个「指向函数的指针」的数组，被指向的函数有1个int参数并返回int。//int(*p[3]) (int );

## 8. 混乱中建立秩序
你对排序算法了解多少呢?
请谈谈你所了解的排序算法的思想、稳定性、时间复杂度、空间复杂度。
提示：动动你的小手敲出来更好哦~



## 9. 手脑并用
请实现ConvertAndMerge函数：
拼接输入的两个字符串，并翻转拼接后得到的新字符串中所有字母的大小写。

提示:你需要为新字符串分配空间。
~~~c
char* convertAndMerge(char *a[2]);
int main(void) {
    char words[2][20] = {"Welcome to Xiyou ", "Linux Group 2022"};
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    char *str = convertAndMerge(words);
    printf("str = %s\n", str);
    free(str);
}
~~~
~~~c
char* convertAndMerge(char a[2][20]){
  char *str11=(char *)malloc(sizeof(char)*40);
  // for(int i=0;i<strlen(a[0]);i++){
  //   str[i]=a[0][i];
  // }
  // for(int i=strlen(a[0]);i<strlen(a[1])+strlen(a[0]);i++){
  //   str[i]=a[1][i-strlen(a[0])];
  // }
    strcpy(str11, a[0]);
    strcat(str11, a[1]);

  for(int i=0;i<strlen(a[1])+strlen(a[0]);i++){
    if(str11[i]>='A' &&str11[i]<='Z') str11[i]+='a'-'A';
    else str11[i]+='A'-'a';
  }
  return str11;
}

int main(void) {
    char words[2][20] = {"Welcome to Xiyou ", "Linux Group 2022"};

    printf("%s,%d\n", words[0],strlen(words[0]));
    printf("%s,%d\n", words[1],strlen(words[1]));
    char *str = convertAndMerge(words);
    printf("str = %s\n", str);
    free(str);
}
~~~



## 10.给你我的指针，访问我的心声
程序的输出有点奇怪，请尝试解释一下程序的输出吧。
~~~c
int main(int argc, char **argv) {
  int arr[5][5];
  int a = 0;
  for (int i = 0; i < 5; i++) {
    int *temp = *(arr + i);//
    for (; temp < arr[5]; temp++) *temp = a++;
  }//将上行的arr[5]改为arr[i+1]，如果是arr[5]，赋值完会被第二轮循环覆盖掉，但是a已经自增了
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%4d", arr[i][j]);
    }
    printf("\n");
  }
}
~~~
输出
>   0   1   2   3   4
  25  26  27  28  29
  45  46  47  48  49
  60  61  62  63  64
  70  71  72  73  74

## 11. 奇怪的参数
你了解argc和argv吗？
直接运行程序argc的值为什么是1？
程序会出现死循环吗？
~~~c
#include <stdio.h>
int main(int argc, char **argv) {
    printf("argc = %d\n", argc);
    while (1) {
        argc++;
        if (argc < 0) {
            printf("%s\n", (char *)argv[0]);
            break;
        }
    }
}
~~~
与2023第9题；

## 12. 奇怪的字符
程序的输出有点奇怪，请尝试解释一下程序的输出吧。
~~~c
int main(int argc, char **argv) {
    int data1[2][3] = {{0x636c6557, 0x20656d6f, 0x58206f74},
                       {0x756f7969, 0x6e694c20, 0x00000000}};
    int data2[] = {0x47207875, 0x70756f72, 0x32303220, 0x00000a32};
    char *a = (char *)data1;
    char *b = (char *)data2;
    char buf[1024];
    strcpy(buf, a);
    strcat(buf, b);
    printf("%s \n", buf);
}
~~~




## 13. 小试宏刀

请谈谈你对#define的理解。
请尝试着解释程序的输出。
~~~c
#define SWAP(a, b, t) t = a; a = b; b = t
#define SQUARE(a) a *a
#define SWAPWHEN(a, b, t, cond) if (cond) SWAP(a, b, t)
int main() {
    int tmp;
    int x = 1;
    int y = 2;
    int z = 3;
    int w = 3;
    SWAP(x, y, tmp);//交换a,b
    printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);//tmp等于a->1; 输出 ，2,1,1；
    if (x > y) SWAP(x, y, tmp);//又交换回去
    printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);//1,2,2；
    SWAPWHEN(x, y, tmp, SQUARE(1 + 2 + z++ + ++w) == 100);//if(1+2+z++ +++w*1+2+z++ + ++w(等于1+2+3+4+2+4+5不等于100)) 所以if后不交换；
    printf("x = %d, y = %d\n", x, y, tmp);//只有前两个，所以为2,2
    printf("z = %d, w = %d, tmp = %d\n", z, w, tmp);//5,5
}
~~~


输出：

> x = 2, y = 1, tmp = 1
x = 1, y = 2, tmp = 2
x = 2, y = 2
z = 5, w = 5, tmp = 2

# 2021

## 1. 大小和长度竟然不是一个意思
sizeof()和strlen()有什么异同之处？

他们对于不同参数的结果有什么不同？请试举例子说明。

```c
int main(void) {
  char s[] = "I love Linux\0\0\0";
  int a = sizeof(s);
  int b = strlen(s);
  printf("%d %d\n", a, b);
}
```

输出
>16 12

23年 3题

## 2. 箱子的大小和装入物品的顺序有关
test1和test2都含有：1个short、1个int、1个double，那么sizeof(t1)和sizeof(t2)是否相等呢？这是为什么呢？

```c
struct test1 {
  int a;
  short b;
  double c;
};
struct test2 {
  short b;
  int a;
  double c;
};
int main(void) {
  struct test1 t1;
  struct test2 t2;
  printf("sizeof (t1) : %d\n", sizeof(t1));
  printf("sizeof(t2): %d\n", sizeof(t2));
}

```

> sizeof (t1) : 16
sizeof(t2): 16


结构体内存对齐：
1结构体的每个成员并不是连续对齐的，
2,其内存为最大的类型*N。
3,所以最好将内存相近的数据放一起。


## 3.哦，又是函数
想必在高数老师的教导下大家十分熟悉函数这个概念。那么你了解计算机程序设计中的函数吗？请编写一个func函数，用来输出二维数组arr中每个元素的值。

```c
/*在这里补全func函数的定义*/
int main(void) {
  int arr[10][13];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 13; j++) {
      arr[i][j] = rand();
    }
  }
  func(arr);
}

```

```c
int main(void) {
  int arr[10][13];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 13; j++) {
      arr[i][j] = rand();
    }
  }
  func(arr);
}

```
## 4.就不能换个变量名吗？
请结合下面的程序，简要谈谈传值和传址的区别。
简要谈谈你对C语言中变量的生命周期的认识。

```c
int ver = 123;//全局变量
void func1(int ver) {
  ver++;
  printf("ver = %d\n", ver);
}
void func2(int *pr) {
  *pr = 1234;
  printf("*pr = %d\n", *pr);//1234
  pr = 5678;
  printf("ver = %d\n", ver);//123 （全局变量）
}
int main() {
  int a = 0;
  int ver = 1025;
  for (int a = 3; a < 4; a++) {
    static int a = 5;
    printf("a = %d\n", a);//5
    a = ver;//1025
    func1(ver);//传的1025，输出1026
    int ver = 7;
    printf("ver = %d\n", ver);//7
    func2(&ver);//
  }
  printf("a = %d\tver = %d\n", a, ver);//1025，for的场结束，ver重新为main函数定义的1025;
}

```
输出

> a = 5
ver = 1026
ver = 7
*pr = 1234
ver = 123
a = 0   ver = 1025

## 5. 套娃真好玩！
请说明下面的程序是如何完成求和的？

```c
unsigned sum(unsigned n) { return n ? sum(n - 1) + n : 0; }
int main(void) { printf("%u\n", sum(100)); }

```

> 5050

递归，三目运算

## 6.算不对的算术


```c
void func(void) {
  short a = -2;
  unsigned int b = 1;
  b += a;//由于b 为无符号数,-1跨过,变为2^32;
  int c = -1;
  unsigned short d = c * 256;//-
  c <<= 4;
  int e = 2;
  e = ~e | 6;//0110,取反再
  d = (d & 0xff) + 0x2022;
  printf("a=0x%hx\tb=0x%x\td=0x%hx\te=0x%x\n", a, b, d, e);
  printf("c=Ox%hhx\t\n", (signed char)c);
}

```

> a=0xfffe        b=0xffffffff    d=0x2022        e=0xffffffff
> c=Oxf0


## 7. 指针和数组的恩怨情仇

```c
int main(void) {
  int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int(*b)[3] = a;
  ++b;
  b[1][1] = 10;
  int *ptr = (int *)(&a + 1);
  printf("%d %d %d \n", a[2][1], **(a + 1), *(ptr - 1));
}

```

> 10 4 9

## 8. 移形换位之术
下面有a、b、c三个变量和4个相似的函数。

你能说出使用这三个变量的值或地址作为参数分别调用这5个函数，在语法上是否正确吗？
请找出下面的代码中的错误。
const int和int const是否有区别？如果有区别，请谈谈他们的区别。
const int *和int const *是否有区别？如果有区别，请谈谈他们的区别。

~~~c
int a = 1;
int const b = 2;
const int c = 3;
void funco(int n) {
  n += 1;
  n = a;
}
void func1(int *n) {
  *n += 1;
  n = &a;
}
void func2(const int *n) {
  *n += 1;
  n = &a;
}
void func3(int *const n) {
  *n += 1;
  n = &a;
}
void func4(const int *const n) {
  *n += 1;
  n = &a;
}
~~~




## 9. 听说翻转字母大小写不影响英文的阅读？
请编写convert函数用来将作为参数的字符串中的大写字母转换为小写字母，将小写字母转换为大写字母。返回转换完成得到的新字符串。

~~~c
char *convert(const char *s);
int main(void) {
  char *str = "XiyouLinux Group 2022";
  char *temp = convert(str);
  puts(temp);
}
~~~
如下
~~~c
char *convert(const char *s){
    char *rst=(char *)malloc(sizeof(char)*strlen(s));
    strcpy(rst,s);

        for(int i=0;i<strlen(s);i++) {
        if(*(rst+i)>='A' && *(rst+i)<= 'Z'){
            *(rst+i)-='A'-'a';
        }else if(*(rst+i)>='a' && *(rst+i)<= 'z') *(rst+i)+='A'-'a';
    }
    return rst;


}
~~~





## 10. 交换礼物的方式
请判断下面的三种Swap的正误，分别分析他们的优缺点。
你知道这里的do {...} while(0)的作用吗？
你还有其他的方式实现Swap功能吗？

~~~c
#define Swap1(a, b, t) 
  do {                 
    t = a;             
    a = b;             
    b = t;             
  } while (0)
#define Swap2(a, b) 
  do {              
    int t = a;      
    a = b;          
    b = t;          
  } while (0)
void Swap3(int a, int b) {
  int t = a;
  a = b;
  b = t;
}
~~~

## 11. 据说有个东西叫参数

~~~c
int main(int argc, char *argv[]) {
  printf("argc = %d\n", argc);
  for (int i = 0; i < argc; i++)
    printf("%s\n", argv[i]);
}
~~~

你知道argc和argv的含义吗？请解释下面的程序。你能在不使用argc的前提下，完成对argv的遍历吗？


argc：外部输入的参数个数
argv：参数的字符串数组，用来存放指向字符串参数的指针数组



## 12. 人去楼空
这段代码有是否存在错误？谈一谈静态变量与其他变量的异同。

~~~c
int *func1(void) {
  static int n = 0;
  n = 1;
  return &n;
}//
int *func2(void) {
  int *p = (int *)malloc(sizeof(int));
  *p = 3;
  return p;
}
int *func3(void) {
  int n = 4;
  return &n;
}
int main(void) {
  *func1() = 4;
  *func2() = 5;
  *func3() = 6;
}
~~~
Segmentation fault段错误



## 13. 奇怪的输出
~~~c
int main(void) {
  int data[] = {0x636c6557, 0x20656d6f, 0x78206f74,
                0x756f7969, 0x6e694c20, 0x67207875,
                0x70756f72, 0x32303220, 0x00000a31};
  puts((const char*)data);
}
~~~


## 14. 请谈谈对从「C语言文件到可执行文件」的过程的理解

