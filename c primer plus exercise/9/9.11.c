//9.11

#include<stdio.h>
double min(double m,double n);
int main(){
  double m,n;
  scanf("%lf%lf",&m,&n);
  printf("%lf",min(m,n)); 
  return 0;

}
double min(double m,double n){
  double h;
  if(m>n) h=n;
  else h=m;
  return h;
}
