#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void ss (void);

typedef  struct shujv{
    unsigned int id   : 8; 
    unsigned int size : 7;
    unsigned int at : 2;
    unsigned int b  : 1;
    unsigned int i  : 1;
    unsigned int u  : 1;
} font;

font  ft ={1 ,12,0,0,0,0};
 
const char * kg[2] ={"off" , "on"};
const char * na[4] ={"left" ,"center","right" };

void kongzhi (void){
    printf(" ID SIZE ALIGNME   B   I   U \n");
    printf("%3d %-8d %-5s %-3s %-3s %-3s\n\n",ft.id,ft.size,na[ft.at],kg[ft.b],kg[ft.i],kg[ft.u]);
    printf("f) change font        s) change size        a) change alignment\n");
    printf("b) toggle bold        i) toggle italic      u) toggle underline\n");
    printf("q) quit\n");
}
void shuc(void)
{
        char ch;
        while(( ch=getchar())!='q'){
            printf("%c\n",ch);
            switch (ch)
            {
            case  'f':
             /* code */
                break;
            case  's':
            ss();
            break;
            case  'a':

            default:
            printf("输出不在范围内 again\n");
            break;
            }
            kongzhi();
        }
}
void ss (void)
{
    printf("Enter font siae  (0-127):");
    unsigned int  n;
    scanf("%d",&n);
    getchar();
    if(n& (~127) !=0){
        ft.size=n;
        printf("\n");
        return ;
    }
    else{
        printf ("\n  (0-127)!!  输入一个again \n");
        ss();
    }
    return ;
}
int main(){

kongzhi();
shuc();
printf("\n结束了 ，拜拜");
return 0;
}

//为什么会重复一遍捏