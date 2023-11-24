#include<stdio.h>
#include<stdlib.h>




int main(){

printf("打到ie看多少个 ，输入#停止");
int count=0;
char ch,ch2='#';
while((ch=getchar())!='#'){
    if(ch2=='i' && ch=='e' ){
        count++;
    }
    ch2=ch;
}
printf("%d",count);
}

