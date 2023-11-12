#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int rst(int day ,char *yuefen);
void runian(int year);
typedef struct yuefen
{   char a2[10];
    char a1[3];
    int mun;
    int  a;
} yue; 

yue months[12] =
{
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int main()
{
    int year,day;
    char month[10];
printf("请输入年月日：(:q退出)\n");
while(scanf("%d%s%d",&year ,month,&day)==3){
runian(year);
int num;
if((num=rst(day,month))>0){
    printf("共%d天\n" ,num);

}else printf("输入不符合条件");

months[1].mun=28;
printf("请输入年月日：(:q退出)\n");

}
printf("结束了再见");
return 0;

}



void runian(int year){
    if(year%4==0 && (year%100!=0 || year%400==0)){
        months[1].mun=29;
    }
}


int rst(int day ,char *yuefen){
    int num=atoi(yuefen);
    if(day<=0 || day >31){
        return -1;
    }
    if(num ==0){
        yuefen[0]=toupper(yuefen[0]);
        for(int i=0 ;yuefen[i]!='\0';i++){
            yuefen[i]=tolower(yuefen[i]);
        }
    }
    int ret=0;
    for(int i=0 ;i <12 ;i++){


        if(strcmp(yuefen,months[i].a1)==0 || strcmp(yuefen,months[i].a2)==0 || num==months[i].a){
            if(day > months[i].mun){
                return -1;
            }
        return ret+day;

        }else  ret= ret+months[i].mun;

    }
    return -1;
    
}