#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    int ch;
    int count=0;
    int da=0,xiao=0;
    int h=0;
    int bai=0;
    int shuzi=0;
    while((ch=getchar())!=EOF && count<10){
        count++;

        if(isalnum(ch)) h++;
        if(islower(ch)) xiao++;
        if(isalpha(ch)) shuzi++;
        if(isupper(ch)) da++;
        if(isspace(ch)) bai++;
        
    }
printf("小写%d 大写%d 空格%d 字符%d 数字%d ",xiao,da,bai,h ,shuzi-h);

}
