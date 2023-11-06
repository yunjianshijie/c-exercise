#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    size_t zhjie;
    FILE * yuanxian;
    FILE * kaobei ;
    char buffer[512]={0};
int main(int argc ,char *argv[])
{
    if(argc !=3){
        fprintf(stderr,"没有文件");
        exit(-1);
    }
    if((yuanxian=fopen(argv[1],"rb"))==NULL){
        fprintf(stderr,"没有初始文件");
        exit(-1);
    }
    if((kaobei=fopen(argv[2],"rw"))==NULL){
        fprintf(stderr,"找不到要拷贝到哪里");
    }
    while(!feof(yuanxian)){
      memset(buffer, 0 ,sizeof(buffer)) ;
      zhjie=fread(buffer,sizeof(char),sizeof(buffer),yuanxian);
    fwrite(buffer,sizeof(char),zhjie,kaobei);
    printf("成功写入");
    }
    if(fclose(yuanxian)!=0||fclose(kaobei)!=0){
        printf("关闭失败\n");
    }
    return 0;
    
}