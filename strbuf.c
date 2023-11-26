#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
struct strbuf {
  int len;     //当前缓冲区（字符串）长度
  int alloc;   //当前缓冲区（字符串）容量
  char *buf;   //缓冲区（字符串）
};


//1A

void strbuf_init(struct strbuf *sb, size_t alloc);
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc);
void strbuf_release(struct strbuf *sb);
void strbuf_swap(struct strbuf *a, struct strbuf *b);
char *strbuf_detach(struct strbuf *sb, size_t *sz);
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second);
void strbuf_reset(struct strbuf *sb);

//2B
void strbuf_grow(struct strbuf *sb, size_t extra);//确保在 len 之后 strbuf 中至少有 extra 个字节的空闲空间可用。
void strbuf_add(struct strbuf *sb, const void *data, size_t len);//向 sb 追加长度为 len 的数据 data。
void strbuf_addch(struct strbuf *sb, int c);//向 sb 追加一个字符 c。
void strbuf_addstr(struct strbuf *sb, const char *s);//向 sb 追加一个字符串 s。
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2);//向一个 sb 追加另一个 strbuf的数据。
void strbuf_setlen(struct strbuf *sb, size_t len);//设置 sb 的长度 len。
size_t strbuf_avail(const struct strbuf *sb);//计算 sb 目前仍可以向后追加的字符串长度。
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len);//向 sb 内存坐标为 pos 位置插入长度为 len 的数据 data。



//3C

void strbuf_rtrim(struct strbuf *sb);//去除 sb 缓冲区左端的所有 空格，tab, '\t'。
void strbuf_ltrim(struct strbuf *sb);//去除 sb 缓冲区右端的所有 空格，tab, '\t'。
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len);//删除 sb 缓冲区从 pos 坐标长度为 len 的内容。

//4D
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint);
int strbuf_getline(struct strbuf *sb, FILE *fp);

//

struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max);
bool strbuf_begin_judge(char *target_str, const char *str, int strnlen);
char *strbuf_get_mid_buf(char *target_buf, int begin, int end, int len);


void strbuf_init(struct strbuf *sb, size_t alloc){
if(alloc>0){
    sb->buf=(char *) malloc(sizeof(char)*(alloc+1));
}
sb->alloc=alloc;
sb->len=0; 
}

void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc){
    
    while(len>alloc){
        alloc*=2;
    }
    
    sb->len=len;
    sb->alloc=alloc;
   sb->buf=(char*)str;
    // (void*)str;
    // for(int i=0; i<len ;i++){
    //     sb->buf[i] = str[i];
    // }
    
}

void strbuf_release(struct strbuf *sb){
    free(sb->buf);
    sb->buf=NULL;
    sb->len=0;
    sb->alloc=0;
}

void strbuf_swap(struct strbuf *a, struct strbuf *b){
    char ab[100];
    struct strbuf t=*a;
    // t.alloc=a->alloc;

   // t.len=a->len;
    // t.buf=a->buf;

    a->len=b->len;
    a->buf=b->buf;
    a->alloc=b->alloc;

    b->alloc=t.alloc;
    b->buf=t.buf;
    b->len=t.len;
    // strcpy(ab,a->buf);
    // strcpy(a->buf,b->buf);
    // strcpy(b->buf,ab);
}

char *strbuf_detach(struct strbuf *sb, size_t *sz)
{
*sz=sb->alloc;
char *h=(char *)malloc(sizeof(char)*(sb->len));
sb->len=0;
sb->alloc=0;
return h;
}


int strbuf_cmp(const struct strbuf *first, const struct strbuf *second){

int a=strlen(first->buf);
int b=strlen(second->buf);
if(first->len>second->len) return 1;
else if(first->len ==second->len) return 0;
else return -1;
// for(int i=0 ;i<a+2 ;i++)
// {
//     if(*(first->buf+i)>*(second->buf+i)){
//         return *(first->buf+i)-*(second->buf+i);
//     }else if((*first->buf+i)<*(second->buf+i)){
//         return -(*first->buf+i)+*(second->buf+i);
//     }

// }

return 0;
}

void strbuf_reset(struct strbuf *sb){

sb->len=0;
sb->buf[0]='\0';
}




// int main() {
//     struct strbuf sb;
//     struct strbuf sb2;
    



// //      strbuf_init(&sb, 10);
// //   strbuf_attach(&sb, "xiyou", 5, 10);
// //   assert(strcmp(sb.buf, "xiyou") == 0);
// //   strbuf_addstr(&sb, "linux");
// //   assert(strcmp(sb.buf, "xiyoulinux") == 0);
// //   strbuf_release(&sb);


// }

//2B




void strbuf_grow(struct strbuf *sb, size_t extra){
if(sb->alloc-sb->len>=extra) return;

while(sb->alloc-sb->len<extra){
    sb->alloc*=2;
}
}

void strbuf_add(struct strbuf *sb, const void *data, size_t len){
if(data=NULL) return ;
char *a=(char*)data;
while (1){
if(sb->alloc>=len+sb->len){
    for(int i=0 ;i<len;i++ ){
        sb->buf[i+sb->len]=a[i];
    }

    sb->buf[len+sb->len]='\0';
    sb->len+=len;
    return ;
}else sb->alloc*=2;
}
}

void strbuf_addch(struct strbuf *sb, int c){
    if(sb->alloc==sb->len) sb->alloc*=2;
    sb->buf[sb->len-1]=c;
    sb->buf[sb->len]='\0';
    sb->len++;
}

void strbuf_addstr(struct strbuf *sb, const char *s){
    int h=strlen(s);
    while(sb->alloc <  sb->len +h){
        sb->alloc*=2;
    }
    for(int i=0 ;i<h ;i++){
    sb->buf[sb->len+i]=s[i];
    }
    sb->len+=h;    
    sb->buf[sb->len]='\0';

}
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2){
    while(sb->alloc < sb->len + sb2->len){
        sb->alloc*=2;
    }
    for(int i=0 ;i<sb2->len ;i++){
        sb->buf[i+sb->len]=sb2->buf[i];
    }
    sb->len+=sb2->len;
    sb->buf[sb->len]='\0';
}


void strbuf_setlen(struct strbuf *sb, size_t len){
    if(sb->len<=len) return ;
    if(sb->len>len) {
        for(int i=len ;i<sb->len ;i++){
                sb->buf[i]='\0';
        }
    }
}


size_t strbuf_avail(const struct strbuf *sb){
    size_t i=sb->alloc-sb->len;
    return i;
}

void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len){
    
  // strbuf_grow(sb, len);
    while(sb->alloc <  sb->len+len ){
        sb->alloc*=2;
    }
    char* a=(char*)data;
    char h[sb->len-pos];
    for(int i=pos; i<sb->len ;i++){
        h[i]=sb->buf[i-pos];
    }
    for(int i=0;i<len ;i++){
        sb->buf[pos+i]=a[i];
    }

    for(int i=0 ;i<  sb->alloc - sb->len - len; i++  ){
        if(sb->buf[i+pos]='\0') break;
        sb->buf[i+pos]='\0';
    }
    for(int i=0 ;i<sb->len-pos;i++){
        sb->buf[i+pos]=h[i];
    }
    sb->buf[len+sb->len]='\0';
    sb->len+=len;

}


//去除 sb 缓冲区左端的所有 空格，tab, '\t'
void strbuf_rtrim(struct strbuf *sb){
int count=0;
while(sb->buf[count]==' ' || sb->buf[count]== '\t'){
    count++;
}
sb->buf=sb->buf+count;
sb->len-=count;
}

void strbuf_ltrim(struct strbuf *sb)//去除 sb 缓冲区右端的所有 空格，tab, '\t'。
{   
    int count=0;
    while(sb->buf[sb->len-count]==' ' || sb->buf[sb->len-count]=='\t'){
        count++;
        sb->buf[sb->len-count]='\0';
    }
    sb->len=sb->len-count;
}


void strbuf_remove(struct strbuf *sb, size_t pos, size_t len)//删除 sb 缓冲区从 pos 坐标长度为 len 的内容。
{   

    if(pos+len<= sb->len)
    {
    for(int i=0 ;i<len ;i++){
        sb->buf[pos+i]=sb->buf[pos+len+i];
    }
    }else{
        for(int i=0 ;i< sb->len-pos;i++){
            sb->buf[pos+i]=sb->buf[pos+len+i];
        }
        for(int i=len-pos ;i<len ;i++){
            sb->buf[i+pos]='\0';
        }
    }

return;

}

//D

//sb 增长 hint ? hint : 8192 大小， 然后将文件描述符为 fd 的所有文件内容追加到 sb 中。
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint){
    
    
    
    return 1;
}

//将 将文件句柄为 fp 的一行内容（抛弃换行符）读取到 sb 。
int strbuf_getline(struct strbuf *sb, FILE *fp){
    return 1;
}


//将长度为 len 的字符串 str 根据切割字符 terminator 切成多个 strbuf,并从结果返回，max 可以用来限定最大切割数量。
//返回 struct strbuf 的指针数组，数组的最后元素为 NULL
struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max)
{
    return ;
}


//target_str : 目标字符串，str : 前缀字符串
//，strlen : target_str 长度 ，前缀相同返回 true 失败返回 false
bool strbuf_begin_judge(char *target_str, const char *str, int strnlen){
    return true;
}

//target_str : 目标字符串，begin : 开始下标，end 结束下标。
//len : target_buf的长度，参数不合法返回 NULL. 下标从0开始，[begin, end)区间。
char *strbuf_get_mid_buf(char *target_buf, int begin, int end, int len){
    return ;
}

