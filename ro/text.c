#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void shi(void){
    fprintf(stderr,"2\n");
}
int main(){
printf("1");
fprintf(stderr,"World!");
fprintf(stdout,"Hello \n");

int a=3;
shi();
return 0;
}