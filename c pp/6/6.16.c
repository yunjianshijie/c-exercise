// 6.16
#include<stdio.h>
int main(){
    int i=0;
    int a=100 ,b=100;
    for(i=0 ; 1 ; i++){
        a+=10;
        b*=1.05;
        if(a<=b){
i++;
break;
        } }
printf("%d",i);
return 0;
}
int main(){
        int i=5;
        do{
        i=(i-1)*5;
        printf("%d\n",i);
}while(i<=150);
        return 0;
}

