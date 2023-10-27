//4.
//4.8.6
// #include<stdio.h>
// #include<string.h>
// int main(){
//     char a[100],b[100];
//     scanf("%s %s",a,b);
//     int m,n;
//     m=strlen(a);
//     n=strlen(b);
//     for(int i=0 ;i<m-1;i++){
//         printf(" ");
//     }
//     printf("%d",n);
//     for(int i=0 ;i<n;i++){
//         printf(" ");
//     }
//     printf("%d",n);
// }


//4.8.7
// #include<stdio.h>
// #include<float.h>
// #define int 
// int main(){
//     double b =1.0/3.0;
//     float  a =1.0/3.0;
//     printf("%.6f %.6lf\n",a,b);
//     printf("%.12f %.12lf\n",a,b);
//     printf("%.16f %.100lf\n",a,b);
//     printf("%f %lf\n",FLT_DIG,DBL_DIG);
//     return 0;

// }
// //FLT_DIG,DBL_DIG 什么东西



//5.7
// #include<stdio.h>
// int lifang(int n){
//     return n*n*n;
// }

// int main(){
//     int i;
//     scanf("%d",&i);
//     printf("%d",lifang(i));
//     return 0;
// }
//5.8
// #include<stdio.h>
// int main(){
//     printf("This program computes moduli.\nEnter an iteg.....;");
//     int n;
//     scanf("%d",&n);
//     int i=1,h;
//     for(i=1 ;1;i++){
//     if(i==1){
//     printf("Now .......");}
//     else printf("EN........");
//     scanf("%d",&h);
//     if(h>0){
//         printf("%d %% %d is %d\n",h,n,h%n);
//     }else{
//         printf("Done");
//         break;
//     }
//     }
//     return 0;}

//5.9
// #include<stdio.h>
// void Temperaturn(double n){
// double i;
// i=5.0/9.0*(n-32);
// double h;
// h=i+273.16;
// printf("摄氏%.2lf,开式%.2lf\n",i,h);
// }
// int main(){
// double a;

// while(scanf("%lf",&a)==1){
// Temperaturn(a);

// }
// return 0;
// }


//6.15
// #include<stdio.h>
// #include<string.h>
// int main(){
//     char a[255];
//     scanf("%s",a);
//     int n=strlen(a);
//     printf("%d",n);
//     for(int i=0 ;i<n ;i++){
//         printf("%c",a[n-i]);

//     }
// return 0;

// }

//6.16
// #include<stdio.h>
// int main(){
//     int i=0;
//     int a=100 ,b=100;
//     for(i=0 ; 1 ; i++){
//         a+=10;
//         b*=1.05;
//         if(a<=b){
// i++;
// break;

//         } }
// printf("%d",i);
// return 0;
// }

//6.18
#include<stdio.h>
int main(){
        int i=5;
        do{
        i=(i-1)*5;
        printf("%d\n",i);
}while(i<=150);
        return 0;
}

