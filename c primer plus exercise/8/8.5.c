#include<stdio.h>
#include<stdlib.h>

#include<time.h>
int main(){
int lift=0 ,right=100;
char ch;
int h=50;
while(1){

printf("猜%d,大了还是小了(h/l/r)\n",h);

scanf("%c",&ch);
if(ch=='l'){
    lift=h-1;
    h=(right-lift)/2+lift;
}else if(ch=='h') {
    right=h+1;
    h=(right-lift)/2+lift;
}else if(ch=='r'){
    printf("bigo");
    break;
}
}
return 0;

}
