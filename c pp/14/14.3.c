#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct book
{
    /* data */
    double mun ;
    int value ;
    char name[40];
    char author[40];
} Book;
Book library[40];

char * s_gets(char* ch[40]);
void sort_title(int n);
 void sort_author(int n);




int main(int agrc, int *agrv[]){
    printf("现在录入图书信息\n");
    printf("输入图书名称\n");
    int count =0;
    char tatil[40];
    
    while(count<40 && s_gets(&library[count].name) && library[count].name[0]!='\0' ){
        printf("输入图书作者\n");
        s_gets(&library[count].author);
        printf("输入图书价格\n");
        scanf("%lf",&library[count].value);
        printf("输入编号\n");
        scanf("%d",&library[count].mun);
        count++;
        if(count<40){
        printf("输入图书名称\n");}
        

    }
    if(count){
        for(int i =0 ;i<count ;i++){
            printf("编号%d 名称%s 作者%s 价格%.2lf\n",library[i].mun,library[i].name,library[i].author,library[i].value);
        }
        
    }

sort_title(count);
for(int i =0 ;i<count ;i++){
            printf("编号%d 名称%s 作者%s 价格%.2lf\n",library[i].mun,library[i].name,library[i].author,library[i].value);
        }
        
sort_author(count);
for(int i =0 ;i<count ;i++){
            printf("编号%d 名称%s 作者%s 价格%.2lf\n",library[i].mun,library[i].name,library[i].author,library[i].value);
        }
        return 0;


}







char* s_gets(char* ch[40] ){
    char* rst ;
    char *find ;
    rst=fgets(*ch,40,stdin);
    find= strchr(*ch,'\n');
    if(find){
        *find ='\0';
    }
    else {
        while(getchar()!='\n'){
            continue;

        }
    }

    return rst;
    }

    void sort_title(int n){
        Book  tmpe;
        for(int i = 0;i<n-1 ;i++){
            for(int j=0 ;j<n-i ;j++){
                if(strcmp(library[j].name,library[j+1].name)>0){
                    tmpe=library[j];
                    library[j]=library[j+1];
                    library[j+1]=tmpe;
                }
            }
        
        }
        //return ;
    }

    void sort_author(int n){
        Book *tmpe ;
        for(int i= 0; i<n-1 ;i++){
            for(int j =0 ; j<n-i ;j++){
                if(strcmp(library[j].author,library[j+1].author)>0){
                    *tmpe=library[j];
                    library[j]=library[j+1];
                    library[j+1]=*tmpe;
                }
            }
        }
        return;
    }


// int main(){
//     int count=0;
//     char ch;
//     printf("Please enter the book title\n");
//     printf("Press [enter] at the start of a line to stop.\n");
//     while ( count<40 && 40){
//         scanf("%s",&library[count].name);
//         printf("now enter authot\n");
//         scanf("%s",&library[count].author);
//         printf("now enter value\n");
//         scanf("%lf",&library[count].value);
//         count++;
//         printf("please enter the book titie(if you jie shu enter q)\n");
//         scanf("%s",&library[count].name);
//         if(library[count].name[0]=='q' && library[count].name[2] =='\n'){
//          count--;   break;
//         }}
        
        
//         int n=count;
//             printf(" %d 书名 %s 作者 %s 价格 %d\n",0,library[0].name,library[0].author,library[0].value);
//             while (n){
//                   printf(" %d 书名 %s 作者 %s 价格 %d\n",n,library[n].name,library[n].author,library[n].value);
//                   n--;
//             }

        



    

// return 0;}