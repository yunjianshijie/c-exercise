//12.7
//
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int main(void)
{
    int n;
    int m;
    n=rand()%100;
    do{
        printf("请输出一个整数：");
        scanf("%d",&m);
        if(m==n){
        printf("恭喜");
        break; }
        else if(m>n){
            printf("大了");
        }else printf("小了");
    }while(1);



}

