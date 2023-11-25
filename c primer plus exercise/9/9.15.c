//9.11 5
#include<stdio.h>
void bianda(double* h,double* g);
int main(void){
  double m,n;
  scanf("%lf%lf",&m,&n);
  bianda(&m,&n);
  printf("%lf %lf",m,n);


  return 0;
}

void bianda(double* h,double* g){
    if(*h>*g) *g=*h;
    else *h=*g;
 
}

