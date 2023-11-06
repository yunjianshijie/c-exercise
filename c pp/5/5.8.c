//5.8
#include<stdio.h>
int main(){
    printf("This program computes moduli.\nEnter an iteg.....;");
    int n;
    scanf("%d",&n);
    int i=1,h;
    for(i=1 ;1;i++){
    if(i==1){
    printf("Now .......");}
    else printf("EN........");
    scanf("%d",&h);
    if(h>0){
        printf("%d %% %d is %d\n",h,n,h%n);
    }else{
        printf("Done");
        break;
    }
    }
    return 0;}