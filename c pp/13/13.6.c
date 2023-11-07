#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// int main(int argc ,char *argv[]){
// FILE *in ,*out ;
// char ch ;
// char name[40];
// int count = 0;
// if(argc <2){
//     fprintf(stderr ,"usage :%s filename \n",argv[0]);
//     exit(EXIT_FAILURE);
// }

// if((in = fopen(argv[1],"r"))==NULL){
//     fprintf(stderr,"can't 打开");
//     exit(EXIT_FAILURE);
// }
// strncpy(name, argv[1], 40-5);
// name[35] = '0';
// strcat(name , ".red");
// if((out = fopen(name ,"w")) == NULL)
// {
//     fprintf(stderr ,"打不开");
//     exit(EXIT_FAILURE);
// }
// while((ch=getc(in))!= EOF){
//     if(count++%3 ==0){
//         putc(ch ,out);
//     }
// }if(fclose(in)!= 0 || fclose(out) != 0){
//         fprintf(stderr ,"Error ");
//     }
//     return 0;

// }


int main(int argc ,char * argv[]){
    FILE *in, *out;
    char ch;
    char name[40];
    int count=0;
    char name1[40];

    printf("输出你想压缩的文件");
    scanf("%s",name);
    if((in=fopen(name ,"r"))==NULL){
        fprintf(stderr,"打不来%s",name);
        exit(EXIT_FAILURE);
    }
    strncpy(name1,name ,35);
    name1[35]='0';
    strcat(name1,".2");

    if((out=fopen(name1,"w"))==NULL){
        fprintf(stderr,"can't dakai");
        exit(EXIT_FAILURE);

    }
    while((ch=getc(in)) != EOF){
         if(count++ %3 == 0)
         {putc(ch,out);}
    }
    if(fclose(out) != 0 || fclose(in) != 0){
        printf("关错误");
    }
    return 0;

}