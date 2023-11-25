#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
 int main(int argc,char *argv[]){
    if(argc==1) printf("没有命令行参数");
    for(int i=argc-1 ;i>0 ;i--){
        printf("%s ",argv[i]);
    }
    printf("\n");
return 0;

 }