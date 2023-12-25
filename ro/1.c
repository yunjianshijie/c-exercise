#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

  //  sb->buf=(char* )malloc(sizeof(char )*(alloc+1));
    strcpy(sb->buf,str);
}

void strbuf_release(struct strbuf *sb){
    free(sb->buf);
    sb->buf=NULL;
    sb->len=0;
    sb->alloc=0;
}

void strbuf_swap(struct strbuf *a, struct strbuf *b){
    char ab[100];
    int ab1=strlen(a->buf);
    int ab2=strlen(b->buf);

    for(int i=0; i<ab1 ;i++)
{
    
    


}
    // strcpy(ab,a->buf);
    // strcpy(a->buf,b->buf);
    // strcpy(b->buf,ab);

}

char *strbuf_detach(struct strbuf *sb, size_t *sz){
*sz=sb->alloc;
char *h=(char *)malloc(sizeof(char)*(sb->len));
;
sb->len=0;
sb->alloc=0;

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




}


int main() {
    struct strbuf sb;
    struct strbuf sb2;
    



//      strbuf_init(&sb, 10);
//   strbuf_attach(&sb, "xiyou", 5, 10);
//   assert(strcmp(sb.buf, "xiyou") == 0);
//   strbuf_addstr(&sb, "linux");
//   assert(strcmp(sb.buf, "xiyoulinux") == 0);
//   strbuf_release(&sb);


}