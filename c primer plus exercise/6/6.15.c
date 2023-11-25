//5.9
#include<stdio.h>
void Temperaturn(double n){
double i;
i=5.0/9.0*(n-32);
double h;
h=i+273.16;
printf("摄氏%.2lf,开式%.2lf\n",i,h);
}
int main(){
double a;

while(scanf("%lf",&a)==1){
Temperaturn(a);

}
return 0;
}