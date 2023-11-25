//9.11 4 调和平均数
#include<stdio.h>
double tiaohe(double m,double n);

int main(){
  double i,j;
  scanf("%lf%lf",&i,&j);
  printf("%lf",tiaohe(i,j));

  return 0;
}
double tiaohe(double m,double n){
  double ret;
  ret=1/((1/m+1/n)/2);
  return ret;
}