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


// int main(){
//         int i=5;
//         do{
//         i=(i-1)*5;
//         printf("%d\n",i);
// }while(i<=150);
//         return 0;
// }

//10.13
// #include<stdio.h>
// #include<stdlib.h>
// void shuru ( double arr[3][5]){
//     for(int i=0 ;i<3 ;i++){
//     for(int j=0 ;j<5 ;j++){
//         scanf("%lf",&arr[i][j]);
//     }}}


// double * pinjun(double arr[3][5])

// {   double *a=(double *)malloc(sizeof(double)*3);
//     double ab[3];
//     a=ab;
//     for(int i=0 ;i< 3 ;i++){
//         for(int j=0 ;j<3 ;j++){
//         ab[i] += arr[i][j];
//         }
//         ab[i]/=5;;
//     }

// return a;
// }
// int main(){
// double a[3][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
// //shuru(a);
// pinjun(a);
//  for(int i=0 ;i<3 ;i++){
//     for(int j=0 ;j<5 ;j++){
//         printf("%lf",a[i][j]);
//     }}
// free(a);
// return 0;    

// }

//???、申请空间越界





//11.14

// #include<stdio.h>
// double mi(double b,int a){
//     if(a==0){
//         return 1;
//     }else return mi(b,a-1)*b;

// }
// double quickmi(double b ,int a){
// if(b==0){
//     return 0;
// }else if(a==0) return 1;
// else if(a&1){
//     return b*quickmi(b,a-1);
// }else return quickmi(b*b,a/2);
// }
// int main(){
// int a;
// double b;
// scanf("%lf%d",&b,&a);
// printf("%lf",quickmi(b,a));


// return 0;
// }

//11.15
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// int panduan(char *hhh,int heihei){
//     for(int i=0;i <heihei ;i++){
//         if(hhh[i]<'9' || hhh[i]>'0'){
//             return 0;
//         }
//     }
//     return 1;


// }
// int main(){
//     char a[10];
//     scanf("%s",a);
//     int b=strlen(a);
//     printf("%d",panduan(a,b));

// return 0;

// }


//11.16
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>


// int main(){
//     char  a[190] ;
//     char  c[2];
//     scanf("%s",a);
//     //printf("%c",a[0]);
//     scanf("%s",c);
//     //printf("%c",c[1]);
//     int b=strlen(a);
//     if(c[0]=='-' && c[1]=='u')
//     {
//     for(int i=0 ;i<b;i++){
//             if(a[i]>'a' && a[i]<'z'){
//                 printf("%c",a[i]+'A'-'a');
//             }else printf("%c",a[i]);
        
//     }}else if (c[0]=='-' && c[1]=='l'){

//         for(int i=0 ; i<b ;i++){
//             if(a[i]>'A' && a[i]<'Z'){
//                 printf("%c",a[i]-'A'+'a');
//             }else printf("%c",a[i]);
//         }
//     }else printf("%s",a);

//     return 0;
// }
//不对呐

//12.7
//
// #include<stdio.h>
// #include<time.h>
// #include<stdlib.h>


// int main(void)
// {
//     int n;
//     int m;
//     n=rand()%100;
//     do{
//         printf("请输出一个整数：");
//         scanf("%d",&m);
//         if(m==n){
//         printf("恭喜");
//         break; }
//         else if(m>n){
//             printf("大了");
//         }else printf("小了");
//     }while(1);



// }

//12.8

// #include<stdio.h>
// int *make_array (int elem ,int val){
// int m;
// int 
    

// }
// void show_array (const int ar [],int n){
    
//     int *pa =(int*)malloc(sizeof(int)*8);
//     int arr[8];
//     pa=arr;
//     for(int i=0 ;i<n ;i++){
//         arr[i]=ar[i];
//     }
// }
// int main(void){
//     int *pa;
//     int size;
//     int value;

//     printf("enter the number of elemwnts:");
//     while(scanf("%d",&size) == 1 && size > 0){
// printf("enter the number of elements:");
// scanf("%d",&value);
// pa=make_array(size ,value);
// if(pa){
// show_array(pa,size);
// free(pa);

// }printf("Enter the numer of elements (<1 to quit):");

// }
// printf("Done \n");
// return 0;
// }



//12.9
// #include<stdio.h>
// int main(){
    


// }



//


