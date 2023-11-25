#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void xiaojia(int a[],int b[],int c[],int size){
    for(int i=0 ;i< size ;i++){
        c[i]=a[i]+b[i];
    }                                                                           
    return ;


}

int main(){
int a[5]={1,2,3,4,5};
int b[5]={1,2,3,4,5};
int c[5]={0};
xiaojia(a,b,c,5);
for(int i=0 ;i<5 ;i++){
    printf("%d ",c[i]);
}
return 0;
}