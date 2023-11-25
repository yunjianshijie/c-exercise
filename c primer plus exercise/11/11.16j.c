//11.16
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    char  a[190] ;
    char  c[2];
    scanf("%s",a);
    //printf("%c",a[0]);
    scanf("%s",c);
    //printf("%c",c[1]);
    int b=strlen(a);
    if(c[0]=='-' && c[1]=='u')
    {
    for(int i=0 ;i<b;i++){
            if(a[i]>'a' && a[i]<'z'){
                printf("%c",a[i]+'A'-'a');
            }else printf("%c",a[i]);
        
    }}else if (c[0]=='-' && c[1]=='l'){

        for(int i=0 ; i<b ;i++){
            if(a[i]>'A' && a[i]<'Z'){
                printf("%c",a[i]-'A'+'a');
            }else printf("%c",a[i]);
        }
    }else printf("%s",a);

    return 0;
}