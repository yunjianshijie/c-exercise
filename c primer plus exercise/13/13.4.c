#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc ,char*argv[]){
    char ch;
    FILE * pf;
    for(int i=1 ;i<argc ;i++){
        pf=fopen(argv[i],"r");
        while((ch = getc(pf))!=EOF)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
    return 0;
}