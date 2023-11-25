//a
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc ,char * argv[]){
    char ch ,ch2;
    int a;
    FILE * fb1 ,*fb2 ,*fb3;
 char str1[256], str2[256];
    if((fb1 = fopen(argv[1],"r")) == NULL || (fb2 =fopen (argv[2],"r"))==NULL)
    {
        fprintf(stderr ,"打开失败");
    }
    char name[20]="13.7.2";
    if((fb3=fopen(name ,"w"))==NULL){
        printf("dfso");
    }
    char *s1 =puts(str1);



    // while(1){
    // while((ch=getc(fb1))!=EOF){
    // putc(ch,fb3);
    // if(ch='\n') break;
    
    // }
    
    // while((ch2=getc(fb2))!=EOF){
    //     putc(ch2,fb3);
    //     if(ch2='\n') break;
    // }
    // if(ch==EOF && ch2 ==EOF){
    //     break;
    // }
    // }
    // if(fclose(fb1)!=0 && fclose(fb2)!=0 && fclose(fb3)!= 0){
    //     printf("关闭失败");
    // }
return 0;
}