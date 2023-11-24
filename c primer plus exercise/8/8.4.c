#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int main()
{
    bool dui;
    int ch;
    int count =0;
    while((ch=getchar())!='\n'){
        if(isspace(ch)){
            count++;
        }
    }
printf("%d",count);
    return 0;
}

//EOF流