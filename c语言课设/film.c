#include "ks.h"
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
struct film head1;
// struct weizi head2;
// struct user head3;
// struct root head4;
// struct root {
//     char name[70];
//     char mima[30];
// } Root[20];
// // 以root 身份进入可以放入新电影，借书，查询电影，排序,位子
// // root 20
// int top1 = 0;
// struct user {
//     char name[70];
//     char mima[30];
//     int xuehao;
//     int a;             // 是否买票
//     struct book *date; // 关联电影
// } User[40];
// // user 40
// int top2 = 0;
// // 可以查询图书，没有人的位置，借一本书，
// // 想要还书提醒
// struct weizi {
//     int lou;    // 楼层
//     int room;   // 房间
//     int number; // 位子号码
//     int a;      // 是否人 1有 0无
// } Weizi[30];
// // Weizi 30
// int top3 = 0;

// struct film {
//     char name[70];        // 名字
//     char author[70];      // 作者
//     int number;           // 编号
//     int month;            // 开始月份
//     int day;              // 开始日期
//     int shi;              // 小时
//     int fen;              // 分钟
//     int a;                // 剩票 1有 0无
//     struct weizi *weizi1; // 位置
//     struct film *next;
// };

void loginfun() {

    printf("---------------------------------------\n");
    printf("               管理系统                \n");
    printf("---------------------------------------\n");
    printf("  以何种身份登录:\n");
    printf("  1.管理员\n");
    printf("  2.用户\n");
    printf("  3.注册\n");
    printf("  0.退出\n");
    printf("----------------------------------------\n");
    printf("  请选择(0-3)\n");
}
//
void signfun() {
    printf("\n");
    printf("---------------------------------------\n");
    printf("               注册界面                \n");
    printf("---------------------------------------\n");
    printf("  以何种身份注册:\n");
    printf("  1.管理员\n");
    printf("  2.用户\n");
    printf("  0.退出\n");
    printf("----------------------------------------\n");
    printf("  请选择(0-2) \n");
};

void rootfun() {
    printf("\n");
    printf("---------------------------------------\n");
    printf("               管理员界面                \n");
    printf("---------------------------------------\n");
    printf("  使用何种功能:\n");
    printf("  1.查询电影信息\n");
    printf("  2.查询用户信息\n");
    printf("  3.添加电影\n");
    printf("  4.添加电影房间：\n");
    printf("  5.修改电影信息\n");
    printf("  6.删除电影信息\n");
    printf("  7.电影排序\n");
    printf("  8.修改密码");
    printf("  0.退出\n");
    printf("----------------------------------------\n");
    printf("  请选择(0-7) \n");
}

void userfun() {
    printf("\n");
    printf("---------------------------------------\n");
    printf("               用户界面                \n");
    printf("---------------------------------------\n");
    printf("  使用何种功能:\n");
    printf("  1.打印用户信息\n");
    printf("  2.查询电影信息\n");
    printf("  3.购买电影票\n");
    printf("  4.退票\n");
    printf("  5.修改密码");
    printf("  0.退出\n");
    printf("----------------------------------------\n");
    printf("  请选择(0-5) \n");
}

void filmseekfun() {
    printf("\n");
    printf("---------------------------------------\n");
    printf("               查询票务界面                \n");
    printf("---------------------------------------\n");
    printf("  查询:\n");
    printf("  1.电影名称\n");
    printf("  2.电影编号\n");
    printf("  3.电影时间）\n");
    printf("  4.电影房间号\n");
    printf("  5.打印全部电影\n");
    printf("  0.退出\n");
    printf("----------------------------------------\n");
    printf("  请选择(0-4)\n");
}

void login(void) {
    loginfun();
    int i = 0;
    scanf("%d", &i);
    if (i == 1) {
        if (login1()) {
            printf("登录成功！");
            root();
        }
        // 账号确认
    } else if (i == 2) {
        if (login2()) {
            printf("登录成功！");
            user();
        }
    } else if (i == 3) {
        sign();
    } else if (i == 0) {
        exit(1); // 直接退出程序
    } else {
        printf("您输入的数字不正确。");
    }
}
bool login1(void) {
    printf("请输入管理员账号：\n");
    char q[70];
    int j = 0;
    int i = 0;
    scanf("%s", q);
    for (; i < top1; i++) {
        if (strcmp(q, Root[i].name) == 0) {
            j = 1;
            break;
        }
    }
    if (j == 0) {
        printf("未发现此账号\n");
        return false;
    } else {
        printf("请输入账号密码：\n");
        char p[30];
        scanf("%s", p);
        if (strcmp(p, Root[i].mima) == 0)
            return true;
        else {
            printf("密码错误！\n");
            return false;
        }
    }
}
bool login2(void) {
    printf("请输入用户账号：\n");
    char q[70];
    int j = 0;
    int i = 0;
    scanf("%s", q);
    for (; i < top2; i++) {
        if (strcmp(q, User[i].name) == 0) {
            j = 1;
            break;
        }
    }
    if (j == 0) {
        printf("未发现此账号\n");
        return false;
    } else {
        printf("请输入账号密码：\n");
        char p[30];
        scanf("%s", p);
        if (strcmp(p, User[i].mima) == 0)
            return true;
        else {
            printf("密码错误！\n");
            return false;
        }
    }
}

void sign() {
    signfun();
    int i = 0;
    scanf("%d", &i);
    if (i == 1) {
        sign1();
    } else if (i == 2) {
        sign2();
    } else if (i == 0) {
        login();
    } else {
        printf("您输入的数字不正确。\n");
    }
}
void sign1(void) {
    if (top1 == 20) {
        printf("账号数目已满20");
        return;
    }
    printf("请输入账号名称：\n");
    scanf("%s", Root[top1].name);
    printf("请输入账号密码：\n");
    scanf("%s", Root[top1].mima);
    printf("\n");
    printf("账号注册成功！\n");
    wrootfile(&Root[top1], "root");
    top1++;
    login();
}
void sign2(void) {
    if (top2 >= 40) {
        printf("账号数目已满\n");
        return;
    }
    printf("请输入账号名称：");
    scanf("%s", User[top2].name);
    printf("请输入账号密码：");
    scanf("%s", User[top2].mima);
    printf("\n");
    printf("账号注册成功！\n");
    wuserfile(&User[top2], "user");
    top2++;
    login();
}

void root(void) {
    while (1) {
        rootfun();
        getchar();
        char i = 0;
        scanf("%c", &i);
        if (i == '1') {        // 查询电影讯息
            filmseek();        // 先打印吧
        } else if (i == '2') { // 查询用户信息
            seekuser2();
        } else if (i == '3') { // 添加电影信息
            addfilm(&head1);
            // 添加后回到root 界面
        } else if (i == '4') { // 添加房间
            addweizi();
        } else if (i == '5') { // 修改电影

        } else if (i == '6') { // 删除电影

        } else if (i == '7') { // 电影排序

        } else if (i == '0') {
            return; // 退出进入登录界面
        }
    }
}

void user() {
    while (1) {
        userfun();
        getchar();
        char i = 0;
        scanf("%c", &i);
        if (i == '1') { // 打印自己用户的信息

            user();
        } else if (i == '2') { // 查询电影信息
            user();
        } else if (i == '3') { // 购买电影票
            root();
        } else if (i == '4') { // 退票
            root();
        } else if (i == '0') {
            return; // 退出进入登录界面
        } else {
            printf("输入不正确");
        }
    }
}
void filmseek() {
    filmseekfun();
    char i = 0;
    getchar();
    scanf("%c", &i);
    if (i == '1' || i == '2' || i == '3' || i == '4' || i == '5') {
        seekfilm1(&head1, i);
    } else if (i == '0') {

    } else {
        printf("你输入的不正确");
    }
}
void addfilm(struct film *n1) { // 添加电影

    struct film *n2 = (struct film *)malloc(sizeof(struct film));
    while (n1->next != NULL) {
        n1 = n1->next;
    }
    printf(" 请输入电影名称:\n");
    scanf("%s", n2->name);
    getchar();
    printf("请输入电影作者:\n");
    scanf("%s", n2->author);
    getchar();
    printf("请输入电影编号：\n"); // 应该检测是否为数字
    scanf("%d", &n2->number);
    printf("请输入电影开始月份：\n");
    scanf("%d", &n2->month);
    printf("请输入电影开始日期：\n");
    scanf("%d", &n2->day);
    printf("请输入电影开始小时：\n");
    scanf("%d", &n2->shi);
    printf("请输入电影开始分钟：\n");
    scanf("%d", &n2->fen);
    printf("请输入电影位置人数：\n");
    scanf("%d", &n2->a);
    n2->next = NULL;
    n1->next = n2;
    wfilmfile(n2, "myfilm");
}

void addweizi() { // 添加房间
    printf("请输入房间楼层：\n");
    scanf("%d", &Weizi[top3].lou);
    printf("请输入房间房号：\n");
    scanf("%d", &Weizi[top3].room);
    printf("请输入房间人数：\n");
    scanf("%d", &Weizi[top3].number);
    top3++;
}

void wrootfile(const struct root *a, const char *filename) {
    FILE *file = fopen(filename, "a"); // 以追加模式打开文件
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }
    fprintf(file, "%s,%s\n", a->name, a->mima); // 将用户信息写入文件
    fclose(file);                               // 关闭文件
}
void wfilmfile(const struct film *a, const char *filename) {
    FILE *file = fopen(filename, "a"); // 以追加模式打开文件
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }
    fprintf(file, "%s,%s,%d,%d,%d,%d,%d\n", a->name, a->author, a->number,
            a->month, a->day, a->shi, a->fen, a->a); // 将用户信息写入文件
    fclose(file);                                    // 关闭文件
}

void rfilmfile(const char *filename) {
    FILE *file = fopen(filename, "r"); // 以读取模式打开文件
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }
    struct film a; // 表示读取除换行
    struct film *c = &head1;
    while (fscanf(file, "\n%[^,],%[^,],%d,%d,%d,%d,%d,%d\n", a.name, a.author,
                  &a.number, &a.month, &a.day, &a.shi, &a.fen,
                  &a.a) != EOF) { // 读取文件中的用户信息
        struct film *b = (struct film *)malloc(sizeof(struct film));
        strcpy(b->name, a.name);
        strcpy(b->author, a.author);
        b->number = a.number;
        b->day = a.day;
        b->shi = a.shi;
        b->fen = a.fen;
        b->a = a.a;
        b->next = NULL;
        c->next = b;
        c = c->next;
    }
    fclose(file); // 关闭文件
}

void rrootfile(const char *filename) {
    FILE *file = fopen(filename, "r"); // 以读取模式打开文件
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }

    struct root a; // 表示读取除换行
    while (fscanf(file, "%[^,],%[^\n]\n", a.name, a.mima) !=
           EOF) { // 读取文件中的用户信息
        strcpy(Root[top1].name, a.name);
        strcpy(Root[top1].mima, a.mima);
        top1++;
    }
    fclose(file); // 关闭文件
}

void wuserfile(const struct user *a, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开user");
        return;
    }
    fprintf(file, "%s,%s", User[top2].name, User[top2].mima);
    fclose(file);
}
void ruserfile(const char *filename) {
    FILE *file = fopen(filename, "r"); // 以读取模式打开文件
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }
    struct user a;
    while (fscanf(file, "%[^,],%[^\n]\n", a.name, a.mima) != // 表示读取除换行
           EOF) { // 读取文件中的用户信息
        strcpy(User[top2].name, a.name);
        strcpy(User[top2].mima, a.mima);
        top2++;
    }
    fclose(file); // 关闭文件

} // 读取文件
// void addroot();

// void adduser(); // 添加

void seekuser1() { // 打印用户
    printf("---------------------------------------\n");
    printf("               现有用户 \n");
    printf("---------------------------------------\n");
    printf(" 用户名 |  用户号 | 是否买票|\n");
    for (int i = 0; i < top2; i++) {
        printf("%s |%d|", User[top2].name, User[top2].xuehao);
    }
} // 没写买票情况

void seekfilm1(struct film *head, char h) {
    char cot[40];
    int b;
    int m = 0, d = 0;
    if (h == '1') {
        printf("请你输入你想要查询的电影名称：");
        scanf("%s", cot);
    } else if (h == '2') {
        printf("请输入你想查询的电影编号：");
        scanf("%d", &b);
    } else if (h == '3') {
        printf("请输入你想查询日期\n");
        printf("月份：");
        scanf("%d", &m);
        printf("\n日期：");
        scanf("%d", &d);
    }
    printf("---------------------------------------------------------------"
           "---\n");
    printf("                            现有场次 \n");
    printf("---------------------------------------------------------------"
           "---\n");
    printf("|   电影名   |    作者   |  编号  |     时间       |     "
           "剩余座位  "
           " |\n");
    struct film *a = head->next;
    while (a != NULL) {

        if ((h == '1' && seekfilm21(a, cot)) ||
            (h == '2' && seekfilm22(a, b)) ||
            (h == '3' && seekfilm23(a, m, d)) || h == '5') {
            printf("| %-10s | %-9s | %-6d | %d-%d_%d:%-8d |    %-9d   |\n",
                   a->name, a->author, a->number, a->month, a->day, a->shi,
                   a->fen, a->a);
        }
        a = a->next;
    }
}; // 打印电影场次

bool seekfilm21(struct film *head, char *cot) {
    if (strcmp(cot, head->name) == 0) {
        return true;
    }
    return false;
} // 查询电影名称

bool seekfilm22(struct film *a, int b) {

    if (b == a->number) {
        return true;
    }
    return false;
}

bool seekfilm23(struct film *a, int m, int d) {

    if (a->day == d && a->month) {
        return true;
    }
    return false;
}
///////////查询电影信息

void seekweizi() {

    printf("---------------------------------------\n");
    printf("               现有房间 \n");
    printf("---------------------------------------\n");
    printf("|   房间楼层   |  房间号 | 座位个数 |  现有座位个数\n");
    for (int i = 0; i < top3; i++) {
        printf("%d |%d|%d| ", Weizi[i].lou, Weizi[i].room, Weizi[i].number,
               Weizi[i].a);
    }
}

void seekuser2() // root查询用户
{
    printf("-----------------------------------------------\n");
    printf("                   现有用户 \n");
    printf("------------------------------------------------\n");
    printf("|   用户名称   |  用户权限 |  用户密码 |用户编号\n");
    for (int i = 0; i < top1; i++) {
        printf("|   %-10s |    root   |   ****    | %d |\n", Root[i].name, i);
    }
    for (int i = 0; i < top2; i++) {
        printf("|   %-10s |   user    | %-9s | %d |\n", User[i].name,
               User[i].mima, i);
    }
}

void seekweizi2(); // 查询位置
void seekuser() {} // 查询自己的信息

int main() {
    rfilmfile("myfilm");
    rrootfile("root");
    ruserfile("user");
    // addfilm(&head1);
    // seekfilm1(&head1);
    struct film *a = head1.next;
    while (a != NULL) {
        printf("1%s\n", a->name);
        a = a->next;
    }
    while (1) {
        login();
    }
    return 0;
}
