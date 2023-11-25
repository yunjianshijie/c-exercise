



//11.14

#include<stdio.h>
double mi(double b,int a){
    if(a==0){
        return 1;
    }else return mi(b,a-1)*b;

}
double quickmi(double b ,int a){
if(b==0){
    return 0;
}else if(a==0) return 1;
else if(a&1){
    return b*quickmi(b,a-1);
}else return quickmi(b*b,a/2);
}
int main(){
int a;
double b;
scanf("%lf%d",&b,&a);
printf("%lf",quickmi(b,a));


return 0;
}
