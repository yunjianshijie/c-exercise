// 13.1
// #include<stdio.h>
// #include<stdlib.h>
// int main(int argc ,char *argv[]){
//     int ch;
//     FILE *fp;
//     unsigned long count =0;
//  //   printf(" argc=%d",argc);
//     if(argc!=2){
//         printf("usage : %s filename\n",argv[0]);
//         exit(EXIT_FAILURE);
//     }
//     if((fp= fopen(argv[1],"r")) ==  NULL){
//         printf("Can't open %s \n",argv[1]);
//         exit (EXIT_FAILURE);
//     }
//     while ((ch =getc(fp))!=EOF){
//         putc(ch , stdout);
//         count++;
//     }
//     fclose(fp);
//     printf("File %s has %lu characters\n",argv[1],count);
//     return 0;}

//上为书中代码

#include<stdio.h>
#include<stdlib.h>
int main(int argc ,char *argv[]){
int ch;
FILE * fp;
unsigned long count =0;
char a[50];
printf("输入文件名字");
scanf("%s",a);
if((fp= fopen(a,"r"))==NULL){
    printf("找不到%s",a);
    exit(EXIT_FAILURE);
}
while((ch=getc(fp))!=EOF){
    printf("%c",ch);
    count++;
}

fclose(fp);
printf("\nfile %s has %lu characters",a,count);
return 0;

}