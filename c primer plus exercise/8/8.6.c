#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char get_first(viod){
    int ch; 
    char h=" ";    
    ch=getchar();
    if(ch!=" ") {h=ch;}
    while(getchar()!='\n'){
    continue;
    }
    return ch;

}



int main(){
    char h=get_first();
    printf("%c",h);
    return 0;

}

