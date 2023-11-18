#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct book
{
    double mun ;
    int value ;
    char name[40];
    char author[40];
} Book;

// char * s_gets(char* ch,int n);
// void sort_title(int n);
//  void sort_author(int n);



    void sort_title(int n,Book *library[40]){
        Book  tmpe;
        for(int i = 0;i<n-1 ;i++){
            for(int j=0 ;j<n-i ;j++){
                if(strcmp(library[j]->name,library[j+1]->name)>0){
                    tmpe=*library[j];
                    *library[j]=*library[j+1];
                    *library[j+1]=tmpe;
                }
            }
        
        }
        //return ;
    }

    void sort_author(int n,Book *library1[40]){
        Book *tmpe ;
        for(int i= 0; i<n-1 ;i++){
            for(int j =0 ; j<n-i ;j++){
                if(strcmp(library1[j]->author,library1[j+1]->author)>0){
                    *tmpe=*library1[j];
                    *library1[j]=*library1[j+1];
                    *library1[j+1]=*tmpe;
                }
            }
        }
        return;
    }



char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

    
int main(int agrc, int *agrv[]){
    Book library[40];
    Book *book [40];

    printf("现在录入图书信息\n");
    printf("输入图书名称\n");
    int count =0;
    char tatil[40];
    
    while(count<40 && (s_gets(library[count].name,40)) && library[count].name[0]!='\0' ){
        printf("输入图书作者\n");
        s_gets(library[count].author,40);
        printf("输入图书价格\n");
        scanf("%lf",&library[count].value);
        printf("输入编号\n");
        scanf("%d",&library[count].mun);
        count++;
        book[count]=&library[count];
         while (getchar() != '\n')
            continue;
        if(count<40){
        printf("输入图书名称\n");}
        

    }
    if(count){
        for(int i =0 ;i<count ;i++){

            printf("编号%d 名称%s 作者%s 价格%.2lf\n",library[i].mun,book[i]->name,book[i]->author,book[i]->value);
        }
        
    }

sort_title(count,&library);
for(int i =0 ;i<count ;i++){
            printf("编号%d 名称%s 作者%s 价格%.2lf\n",library[i].mun,library[i].name,library[i].author,library[i].value);
        }
        
sort_author(count,&library);
for(int i =0 ;i<count ;i++){
            printf("编号%d 名称%s 作者%s 价格%.2lf\n",library[i].mun,library[i].name,library[i].author,library[i].value);
        }
        return 0;

}


// char* s_gets(char* ch[40] ){
//     char* rst ;
//     char *find ;
//     rst=fgets(ch,40,stdin);
//     find= strchr(ch,'\n');
//     if(find){
//         *find ='\0';
//     }
//     else {
//         while(getchar()!='\n'){
//             continue;

//         }
//     }

//     return rst;
//     }





// #include <stdio.h>
// #include <string.h>
// #define MAXTITL 40
// #define MAXAUTL 40
// #define MAXBKS 100

// struct book
// {
//     char title[MAXTITL];
//     char author[MAXAUTL];
//     float value;
// };

// char *s_gets(char *st, int n);
// void sort_title(struct book *pb[], int n);
// void sort_value(struct book *pb[], int n);

// int main(void)
// {
//     struct book library[MAXBKS];
//     struct book *book[MAXBKS];
//     int count = 0;
//     int index;

//     printf("Please enter the book title.\n");
//     printf("Press [enter] at the start of a line to stop.\n");
//     while (count < MAXBKS && s_gets(library[count].title, MAXTITL) && library[count].title[0] != '\0')
//     {
//         printf("Now enter the author.\n");
//         s_gets(library[count].author, MAXAUTL);
//         printf("Now enter the value.\n");
//         scanf("%f", &library[count].value);
//         book[count] = &library[count];
//         count++;
//         while (getchar() != '\n')
//             continue;
//         if (count < MAXBKS)
//         {
//             printf("Enter the next title.\n");
//         }
//     }

//     if (count > 0)
//     {
//         printf("Here is the list of your books:\n");
//         for (index = 0; index < count; index++)
//         {
//             printf("%s by %s: $%.2f\n", library[index].title,
//                    library[index].author, library[index].value);
//         }
//         sort_title(book, count);
//         printf("\nHere is the list of your books sorted by title letters:\n");
//         for (index = 0; index < count; index++)
//         {
//             printf("%s by %s: $%.2f\n", book[index]->title,
//                    book[index]->author, book[index]->value);
//         }
//         sort_value(book, count);
//         printf("\nHere is the list of your books sorted by value(from low to high):\n");
//         for (index = 0; index < count; index++)
//         {
//             printf("%s by %s: $%.2f\n", book[index]->title,
//                    book[index]->author, book[index]->value);
//         }
//     }
//     else
//     {
//         printf("No books? Too bad.\n");
//     }

//     return 0;
// }

// void sort_title(struct book *pb[], int n)
// {
//     int i, j;
//     struct book *temp;

//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = i + 1; j < n; j++)
//         {
//             if (strcmp(pb[j]->title, pb[i]->title) < 0)
//             {
//                 temp = pb[j];
//                 pb[j] = pb[i];
//                 pb[i] = temp;
//             }
//         }
//     }
//     return;
// }

// void sort_value(struct book *pb[], int n)
// {
//     int i, j;
//     struct book *temp;

//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = i + 1; j < n; j++)
//         {
//             if (pb[j]->value < pb[i]->value)
//             {
//                 temp = pb[j];
//                 pb[j] = pb[i];
//                 pb[i] = temp;
//             }
//         }
//     }
//     return;
// }












































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