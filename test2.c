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
// #include<stdio.h>
// int main(){
//         int i=5;
//         do{
//         i=(i-1)*5;
//         printf("%d\n",i);
// }while(i<=150);
//         return 0;
// }


// #include<stdio.h>

// int baozha(int a){
    
// for(int i=0 ;i <3 ;i++){

// a=baozha( a);
// }
// return a;
// }
// int main(){

// int b=baozha(1);
// printf("%d",b);
// return 0;
// // }

// #include<stdio.h>
// char* meila(int b){
//     char *a=(char*)malloc(sizeof(char)*12);
//     a="fdksf f";
//    char b[2]="qq";
//     //*(a+1)='c';
//    b [10000000000]='2';

// return a;


// }
// int main(){
//     printf("%s\n",meila(1));

//     return 0;

// }

// #include<stdio.h>
// int main(){
// int b=1;
//     while(1)
// {
//     int n=(int *)malloc(sizeof(int)*10000);
//     b++;
// }
// printf("%d",b);
// free(a)
// }


// #include<stdio.h>
// int main(){
    
// }
    #include<stdlib.h>
    #include<string.h>
 #include<stdio.h>
// #define SWAP(a, b, t) t = a; a = b; b = t
// #define SQUARE(a) a *a
// #define SWAPWHEN(a, b, t, cond) if (cond) SWAP(a, b, t)
// int main() {
//     int tmp;
//     int x = 1;
//     int y = 2;
//     int z = 3;
//     int w = 3;
//     SWAP(x, y, tmp);//交换a,b
//     printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);//tmp等于a->1; 输出 ，2,1,1；
//     if (x > y) SWAP(x, y, tmp);//又交换回去
//     printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);//1,2,2；
//     SWAPWHEN(x, y, tmp, SQUARE(1 + 2 + z++ + ++w) == 100);//if(1+2+z++ +++w*1+2+z++ + ++w(等于1+2+3+4+2+4+5)) 
//     printf("x = %d, y = %d\n",x,y);//2,2
//     printf("z = %d, w = %d, tmp = %d\n", z, w, tmp);//5,5
// }


struct test1 {
  int a;
  short b;
  double c;
};
struct test2 {
  short b;
  int a;
  double c;
};
int main(void) {
  struct test1 t1;
  struct test2 t2;
  printf("sizeof (t1) : %d\n", sizeof(t1));
  printf("sizeof(t2): %d\n", sizeof(t2));
}

