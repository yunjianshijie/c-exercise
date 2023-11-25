#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct shebao 
{
    /* data */
    int  haoma;
    char name [3][20];
} Shei;
Shei h[5]={0};


// a

void shuru (Shei * a,int n){
for(int i=0 ; i<n;i++){
scanf("%d%s%s%s",&(a+i)->haoma,(a+i)->name[0],(a+i)->name[1],(a+i)->name[3]);
}
}
void shuchu (Shei * a ,int n){
    for(int i=0 ;i <n ;i++){
        printf("%d  %s  %s -%c",(a+i)->haoma ,(a+i)->name[0],(a+i)->name[3],*(a+i)->name[2]);
    }
    
}

//b
int main (){


    


}