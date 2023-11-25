//11.15
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int panduan(char *hhh,int heihei){
    for(int i=0;i <heihei ;i++){
        if(hhh[i]<'9' || hhh[i]>'0'){
            return 0;
        }
    }
    return 1;


}
int main(){
    char a[10];
    scanf("%s",a);
    int b=strlen(a);
    printf("%d",panduan(a,b));

return 0;

}
