#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct qui{
int num;//编号
char name [20];//名
char xi [20];//性
int chu;//出场次数
int ji;//击中
int zhuo ;//走垒数
int da; //打点
double lv; //安打率

}  Qui;

 int dushujiu (FILE * fp , Qui*a , int n){
int count=0;
int num;//编号
char name [20];//名
char xi [20];//性
int chu;//出场次数
int ji;//击中
int zhuo ;//走垒数
int da; //打点
double lv; //安打率
while ((fscanf(fp ,"%d %20s %s %d %d %d %d",&num ,name ,xi ,&chu ,&ji,& zhuo ,&da)) ==7  && count <n){
     printf("%d %s %s %d %d %d %d\n",num ,name ,xi ,chu ,ji,zhuo ,da);
    (a+count)->num =num;

    strcpy ((a+count)->name,name);
    strcpy ((a+count)->xi,xi);
    (a+count)->chu =chu;
    (a+count)->ji =ji;
    (a+count)->zhuo =zhuo;
    (a+count)->da =da;
   
    printf("%d %s %s %d %d %d %d\n",(a+count)->num ,(a+count)->name ,(a+count)->xi ,(a+count)->chu ,(a+count)->ji,(a+count)->zhuo ,(a+count)->da);
     count++;
     if(feof(fp)) break;
}
printf("%d \n",count);

return  count;

 }

int   zhongjie (Qui *a ,Qui *b ,int n){
    for(int i =0 ;i<n ;i++){
        for(int j =1+i ;j<n ;j++){
            if((a+i)->num == (a+j)->num && (a+j)->num!=-1){
                (a+i)->chu +=(a+j)->chu;
                (a+i)->da  +=(a+j)->da;
                (a+i)->ji  +=(a+j)->ji;
                (a+i)->zhuo+=(a+j)->zhuo;
                (a+j)->num=-1;
                
            }
        }
    }
    int ret=0;
    for(int i =0 ;i < n ;i++){
        if((a+i)->num>=0){
            (a+i)->lv=((double)(a+i)->ji+(a+i)->chu+(a+i)->da+(a+i)->zhuo)/4;
        }
    }
return ret;
}
void shuchu (Qui * a ,int n){
 for(int i=0 ;i<n ;i++)
  {
  if((a+i)->num >=0)  printf("%d %s %s %d %d %d %d %.3lf\n",(a+i)->num ,(a+i)->name ,(a+i)->xi ,(a+i)->chu ,(a+i)->ji,(a+i)->zhuo ,(a+i)->da,(a+i)->lv);
  }
  



}

int main (int argc ,char *argv[]){
    FILE *fp ;
    Qui tame [20];
    Qui zhuihuo[20];
    if((fp=fopen(argv[1],"r"))==NULL){
        printf("文件打开失败");
        exit (EXIT_FAILURE);
    }
    int n = dushujiu(fp ,tame,20);
    
    int h = zhongjie(tame,zhuihuo,20);
    printf("%d\n",h);
    shuchu(tame, n);
    //printf("%d %s %s %d %d %d %d\n",tame[0].num ,tame[0].name ,tame[0].xi ,tame[0].chu ,tame[0].ji,tame[0].zhuo ,tame[0].da);
    

    return 0;
}

//输出发现 0 的问题 ，在第二个函数变为随机数；




