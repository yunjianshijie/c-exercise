#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
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

void loginfun();       // 登录
void signfun();        // 注册
void rootfun();        //
void userfun();        //
void filmseekfun();    // 电影查询
void modfiy_filmfun(); // 电影修改
void sortfun();
// 图形界面
void login(void); // loninfun功能 登录
int login1();     // root
int login2();     // user
void sign();      // signfun的功能 注册
void sign1();     // root
void sign2();     // user
//
void root(int index);          // rootfun的功能
void user(int index);          // userfun的功能
void filmseek();               // 电影查询功能
void addfilm(struct film *n1); // 添加电影
void addweizi();               // 添加房间
//
void wfile(const struct user *a, const char *filename);
void wrootfile(const struct root *a, const char *filename);
void wuserfile(const struct user *a, const char *filename);
// 添加文件保存
void rrootfile(const char *filename);
void ruserfile(const char *filename); // 读取文件
void wfilmfile(const struct film *a, const char *filename);
void rfilmfile(const char *filename);
//  void addroot();                    // 添加管理员
//  void adduser();                    // 添加用户
void seekuser1();                                 // 打印用户
void seekuser3(int index);                        // 打印当前登录用户
void seekfilm1(struct film *head, char h);        // 打印电影
void seekweizi();                                 // 打印房间
void seekuser2();                                 // 查询用户
bool seekfilm21(struct film *head, char *cot);    // 查询电影名称
bool seekfilm22(struct film *head, int b);        //  查询电影编号
bool seekfilm23(struct film *head, int m, int d); // 查询电影时间

void seekweizi(); // 查询位置

void modfiy_film();                       // modfiy_filmfun修改电影功能
struct film *seekfile3(int index, int h); // 查询电影返回

void mimachange_root();
void mimachange_user(int index);
// 修改用户密码
void delete_film();    // 删电影
void buyfilm(int us);  // 买票
void freefilm(int us); // 退票
                       //
                       //

void sort1();

void qqsort1(char index);
struct film *sort(struct film *head, char index); // 归并排序
struct film *getmin(struct film *head);
struct film *merge(struct film *left, struct film *right,
                   char index); // 合并两个链表
// 排序
void tongji(struct film *head);

void wrootfile2();
void wuserfile2();
void wfilmfile2(); // 最后保存修改删除数据

void stop();
void signal_handler(int signum); // 截断ctrl+c