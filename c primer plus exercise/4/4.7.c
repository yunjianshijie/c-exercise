

//4.8.7
#include<stdio.h>
#include<float.h>
#define int 
int main(){
    double b =1.0/3.0;
    float  a =1.0/3.0;
    printf("%.6f %.6lf\n",a,b);
    printf("%.12f %.12lf\n",a,b);
    printf("%.16f %.100lf\n",a,b);
    printf("%f %lf\n",FLT_DIG,DBL_DIG);
    return 0;

}
//FLT_DIG,DBL_DIG 什么东西

