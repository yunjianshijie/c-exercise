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
//char *h=(char *)malloc(sizeof(char)*(sb->len));
sb->len=0;
sb->alloc=0;
return sb->buf;
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
sb->buf=(char*)realloc(sb->buf,sizeof(char)*sb->alloc);
}

void strbuf_add(struct strbuf *sb, const void *data, size_t len){
if(data==NULL) return ;
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
return;
}
//向 sb 追加一个字符 c
void strbuf_addch(struct strbuf *sb, int c){
if(sb->alloc<=sb->len+1){
     sb->alloc*=2;
     char *new_buf = (char *)realloc(sb->buf, sb->alloc * sizeof(char));
     sb->buf=new_buf; 
     }
    sb->buf[sb->len]=(char)c;
     sb->len++;
    sb->buf[sb->len]='\0';
}

void strbuf_addstr(struct strbuf *sb, const char *s){
    int h=strlen(s);
    while(sb->alloc <=  sb->len +h+1){
    sb->alloc*=2;
    char *new_buf = (char *)realloc(sb->buf, (sb->alloc) * sizeof(char));
    sb->buf=new_buf; 
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
    char *new_buf = (char *)realloc(sb->buf, sb->alloc * sizeof(char));
    sb->buf=new_buf; 
    }
    for(int i=0 ;i<sb2->len ;i++){
        sb->buf[i+sb->len]=sb2->buf[i];
    }
    sb->len+=sb2->len;
    sb->buf[sb->len]='\0';
}

//设置 sb 的长度 len。
void strbuf_setlen(struct strbuf *sb, size_t len){
    if(sb->len<=len) {sb->len=len;   return ;}
    if(sb->len>len) {
        for(int i=len ;i<sb->len ;i++){
                sb->buf[i]='\0';
        }
        sb->len=len;
    }
}


size_t strbuf_avail(const struct strbuf *sb){
    size_t i=sb->alloc-sb->len-1;
    return i;
}

void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len){
    
  // strbuf_grow(sb, len);
    while(sb->alloc <= sb->len+len+1 ){
        sb->alloc*=2;

    }
    // char* a=(char*)data;
    // char h[sb->len-pos];
    // for(int i=pos; i<sb->len ;i++){
    //     h[i]=sb->buf[i-pos];
    // }

    // for(int i=0;i<len ;i++){
    //     sb->buf[pos+i]=a[i];
    // }
    char h[sb->len];
    memcpy(h,sb->buf+pos,sb->len-pos);

    memcpy(sb->buf+pos,data,len);
    sb->buf[pos+len]='\0';
    memcpy(sb->buf+pos+len,h,strlen(h));    
    // for(int i=0 ;i<  sb->alloc - sb->len - len; i++  ){
    //     if(sb->buf[i+pos]=='\0') break;
    //     sb->buf[i+pos]='\0';
    // }
    // for(int i=0 ;i<sb->len-pos;i++){
    //     sb->buf[i+pos]=h[i];
    // }
    sb->buf[len+sb->len]='\0';
    sb->len+=len;
}


//c

//去除 sb 缓冲区左端的所有 空格，tab, '\t'
void strbuf_ltrim(struct strbuf *sb){
int count=0;
while((sb->buf[count]==' ' || sb->buf[count]== '\t')&&count <sb->len ){
    count++;
}
char a[sb->len];
for(int i=count ;i<sb->len;i++){
a[i-count]=*(sb->buf+i);
}
memcpy(sb->buf,a,sb->len-count);
sb->buf[sb->len-count]='\0';
// sb->buf=sb->buf+count;   //malloc后的指针 最好别动；
sb->len-=count;
}

void strbuf_rtrim(struct strbuf *sb)//去除 sb 缓冲区右端的所有 空格，tab, '\t'。
{   
    int count=0;
    while(sb->buf[sb->len-count-1]==' ' || sb->buf[sb->len-count-1]=='\t'){
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
    sb->len-=len;

return;

}

//D


//sb 增长 'hint ? hint : 8192' 大小， 然后将文件描述符为 fd 的所有文件内容追加到 sb 中。
//read  函数：
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint){
    if(fd==-1 || sb==NULL){
        return 0;
    }

    // sb->alloc+=hint ?hint : 8192;
    // sb->buf=(char*)realloc(sb->buf,sizeof(char)*(sb->len+hint));
    
    strbuf_grow(sb,(hint ? hint : 8192)+1);
    char *ch=(char *)malloc(sizeof(char)*hint);
    ssize_t len=0;
    ssize_t r;
    if( ( r=read(fd,ch,hint))>0){
   // strbuf_addstr(sb,ch);//追加字符串
    for(int i=0 ;i<r ;i++){

        sb->buf[i+sb->len]=ch[i];
        sb->buf[sb->len+i+1]='\0';
    }
    sb->len+=r;
    len+=r;
    }
    free(ch);
    return len;
}


// ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint){
//     FILE * a;
//     a=fopen(fd,"r");
//     char ch;
//     while ((ch=getc(a))!=)
//     {
//         /* code */
//     }
    



// }



//将 将文件句柄为 fp 的一行内容（抛弃换行符）读取到 sb 。
int strbuf_getline (struct strbuf *sb, FILE *fp){
    if(feof(fp)) return 0;
    int ch;
    while((ch=fgetc(fp))!=EOF){
        if(ch!='\n'){
        strbuf_addch(sb,ch);
        }else {break;}
    }
    return true;
}


// 将长度为 len 的字符串 str 根据切割字符 terminator 切成多个 strbuf,并从结果返回，max 可以用来限定最大切割数量。
// 返回 struct strbuf 的指针数组，数组的最后元素为 NULL

// struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max)
// {
//     int max_t=0;
//     char ter=(char)terminator;
    // for(int i=1; i<len ;i++){
    //     if(*(str+i)==ter && *(str+i-1)!=ter){
    //         max_t++;
    //     }
    // }
    // if(*(str+len-1)==ter){
    //     max_t--;
    // }
//     struct strbuf **p=(struct strbuf **)malloc(sizeof(struct strbuf*)*(max_t+1));
//     if (p == NULL) {
//         // 处理内存分配失败的情况
//         return NULL;
//     }
//     int count=0;
//     int i=0;
//     for(;i<max_t;i++){
//         while(*(str+count)==ter){
//             count ++;
//         }
//         int lift=count;
//         while(*(str+count)!=ter){
//             count++;
//         }
//         int right=count;
//         p[i]=(struct strbuf*)malloc(sizeof(struct strbuf*));
//         if (p[i] == NULL) {
//             // 处理内存分配失败的情况
//             // 在返回 NULL 前释放已分配的内存
//             for (int j = 0; j < i; j++) {
//                 free(p[j]->buf);
//                 free(p[j]);
//             }
//             free(p);
//             return NULL;
//         }
//         p[i]->buf=(char*)malloc(sizeof(char)*(right-lift+1));
        
//         memcpy(p[i]->buf,str+lift ,right-lift);
//         p[i]->buf[right - lift] = '\0'; // 给复制的子字符串添加结束符
//         p[i]->alloc=len;
//         p[i]->len=right-lift;
       
//     }


struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max)
{
    int max_t = 1; // 初始化为1，表示至少有一个分割后的字符串
    char ter = (char)terminator;

    // 计算分割符的个数
     for(int i=1; i<len ;i++){
        if(*(str+i)==ter && *(str+i-1)!=ter){
            max_t++;
        }
    }
    if(*(str+len-1)==ter){
        max_t--;
    }
    max_t=max_t>max? max :max_t;
    struct strbuf **p = (struct strbuf **)malloc(sizeof(struct strbuf *) * (max_t + 1));
    if (p == NULL) {
        // 处理内存分配失败的情况
        return NULL;
    }

    int count = 0;
    int i = 0;
    int start = 0; // 记录当前子字符串的起始位置
    for (; i < max_t; i++) {
        // 下一个子字符串的起始位置
        while(count<len && *(str+count)==ter)
        { count++;}
        start=count;
        // 找到下一个分割符的位置
        while (count < len && str[count] != ter) {
            count++;
        }

        // 分配内存给子字符串的 struct strbuf
        p[i] = (struct strbuf *)malloc(sizeof(struct strbuf));
        // 计算并分配内存给当前子字符串
        size_t sub_len = count - start;
        p[i]->buf = (char *)malloc(sizeof(char) * (sub_len + 1));
        // 复制子字符串到 p[i]->buf
        memcpy(p[i]->buf, str + start, sub_len);

        p[i]->buf[sub_len] = '\0'; // 添加字符串结束符
        p[i]->alloc = sub_len + 1;
        p[i]->len = sub_len;
        start=count++;
    }
    p[max_t] = NULL; // 添加结尾的 NULL
    return p;
}



// if(i>=max){
//     strcpy(p[i]->buf ,b);
// }
// return p;}

// struct strbuf** strbuf_split_buf(const char *str, size_t len, int terminator, int max) {  

//     struct strbuf** p=(struct strbuf**)malloc(sizeof(struct strbuf*)*(max+1));
//     //*p =NULL;
//     char  a[len+1];
//     strcpy(a, str);
//     char delim[2];
//     delim[0] = (char)terminator;
//     delim[1] = '\0';
//     char *b;
//     int i = 0;
//     b = strtok(a, delim);
//     int count;

//     while (b != NULL && i < max- 1) {  
//     p[i] = (struct strbuf*)malloc(sizeof(struct strbuf)); 
//     p[i]->buf= (char*)malloc(sizeof(char)*len);
//     p[i]->len = 0;
//     p[i]->alloc = len;  
//     memcpy(p[i]->buf, b, strlen(b));
//     p[i]->len = strlen(b);
//         b = strtok(NULL, delim);
//         i++;  
//     }
//     p[i-1]=NULL;
//     p=(struct strbuf**)realloc (p ,sizeof(struct strbuf*)*(max+1));
//     return p;

// }  


//target_str : 目标字符串，str : 前缀字符串
//，strlen : target_str 长度 ，前缀相同返回 true 失败返回 false
bool strbuf_begin_judge(char *target_str, const char *str, int strnlen){
    
    if(target_str==NULL || str==NULL ||strnlen<=0){
        return true;
    }
    
    if(strnlen<strlen(str)) return false;

    if(strncmp(str,target_str,strlen(str))==0) return true;
    // for(int i=0;i<strlen(str) ;i++){
    //     if(str[i]!=target_str[i]){
    //         return false;
    //     }
    // }
    return false;

}

//target_str : 目标字符串，begin : 开始下标，end 结束下标。
//len : target_buf的长度，参数不合法返回 NULL. 下标从0开始，[begin, end)区间。
char *strbuf_get_mid_buf(char *target_buf, int begin, int end, int len){
    if(end>len) return NULL;
    char *a =(char*)malloc(sizeof(char)*(end-begin+1));
    memcpy(a,target_buf+begin,end-begin);
    a[end-begin]='\0';
    return a;
}
