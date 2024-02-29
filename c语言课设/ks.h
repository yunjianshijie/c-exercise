
#include <stdbool.h>
struct root {
    char name[70];
    char mima[30];
} Root[20];
// 以root 身份进入可以放入新电影，借书，查询电影，排序,位子
// root 20
int top1 = 0;
struct user {
    char name[70];
    char mima[30];
    int xuehao;
    int a;             // 是否买票
    struct book *date; // 关联电影
} User[40];
// user 40
int top2 = 0;
// 可以查询图书，没有人的位置，借一本书，
// 想要还书提醒
struct weizi {
    int lou;    // 楼层
    int room;   // 房间
    int number; // 位子号码
    int a;      // 是否人 1有 0无
} Weizi[30];
// Weizi 30
int top3 = 0;

struct film {
    char name[70];        // 名字
    char author[70];      // 作者
    int number;           // 编号
    int month;            // 开始月份
    int day;              // 开始日期
    int shi;              // 小时
    int fen;              // 分钟
    int a;                // 剩票 1有 0无
    struct weizi *weizi1; // 位置
    struct film *next;
};

void loginfun(); // 登录
void signfun();  // 注册
void rootfun();  //
void userfun();
// 图形界面
void login(void); // loninfun功能
bool login1();    // root
bool login2();    // user
void sign();      // signfun的功能
void sign1();     // root
void sign2();     // user
//
void root();                   // rootfun的功能
void addfilm(struct film *n1); // 添加电影
void addweizi();               // 添加房间
void userfile(const struct user *a, const char *filename);
void rootfile(const struct root *a, const char *filename);
// 添加文件保存
//  void addroot();                    // 添加管理员
//  void adduser();                    // 添加用户
void seekuser1();                  // 打印用户
void seekfilm1(struct film *head); // 打印电影
void seekweizi();                  // 打印房间
void seekuser2();                  // 查询用户
void seekfilm2(struct film *head); // 查询电影
void seekweizi();                  // 查询位置
