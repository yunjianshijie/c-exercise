 #define _CRT_SECURE_NO_WARNING
// /*#include<stdio.h>
// int main(){
//     float a=0.3;
//     float b=0.5;
//     printf("%.100f",a+b);
//     printf("%.100f",0.8);
//     return 0;
//     if((int)(a+b)*1000==(int)0.8*1000){
//         printf("yes");
//     }else printf("no");
    
// }
// /*#include<stdio.h>=
// int main(){
// double a,b,c;
// scanf("%lf,%lf,%lf",&a,&b,&c);
// printf("%.6lf",(a+b)*c/2);
// return 0;
// }*/
//#include<stdio.h>
//int main(){
//char a;
//scanf("%s",&a);
//char A;
//A=a+'A'-'a';
//printf("%s",A);
//return 0;
//}
//#include<stdio.h>
//int main(){
//float F=80;
//float C=5*(F-32)/9;
//printf("%2.6f",C);
//return 0;
//}
// #include<stdio.h>
// int main(){
// int m;
// scanf("%d",&m);
// int n;
// while(m!=0){
// n=(m/10)+n*10;
// m/=10;
// }
// printf("%03d",n);
// return 0;
// }

// #include<stdio.h>
// int main(){
// int a;
// scanf("%d",&a);
// int h=a;
// int m=0;
// int i=1;
// while(a!=0){
	
// m=(a%10)*i+m;
// a/=10;
// i*=8;
// }
// printf("%d(8)=%d(10)",h,m);

// return 0;
// }


//选择排序先来试试~
// #include<stdio.h>
// int main(){
//     int a[10]={4,6,7,3,7,6,5,24,67,76};
//     for(int i=0;i<10;i++){
//           int k=a[i];
//           int m=i;
//           int j;
//         for(j=0;j<10-i;j++){
//           if(a[j+i]<k){
//             k=a[j+i];
//             m=j+i;
//           }
         
            

//         } int t=a[i];
//           a[i]=k;
//           a[m]=t;
//     }
//     for(int i=0;i<10;i++){
//         printf("%d ",a[i]);
//     }
//     return 0;
// }

//选择排序函数
// #include<stdio.h>
// void swap(int* a,int*b);
// void SelectSort(int *arr,int n);
// int main(){
// int arr[10]={0,9,8,7,6,5,4,3,2,3};
// SelectSort(arr,10);
// for(int i=0;i<10;i++){
//   printf("%d",arr[i]);
// }
// return 0;
// }





// void swap(int *a,int*b){
//   int t=*a;
//   *a=*b;
//   *b=t;
// }
// void SelectSort(int arr[],int n){
//   int begin=0 , end=n-1;
//   while(begin < end)
// {
//   int maxi=begin;
//   int mini=begin;
//   for(int i=begin ;i <=end;i++){
//     if(arr[i] <arr[mini]){
//       mini =i;
//     }
//     if(arr[i] > arr[maxi]){
//       maxi=i;
//     }
//   }
//   swap(&arr[mini],&arr[begin]);
//   if(begin ==maxi){
//     maxi=mini;
//   }
//   swap(&arr[maxi],&arr[end]);
//   begin++;
//   end--;
// }}
//选择排序的递归；








//桶排序，先试一下

// #include<stdio.h>
// int main(){


// }
//试不了一点；

// 
// #include<stdio.h>
// #include<stdlib.h>
// #include <string.h>
// int main(){
//   char arr1[] ="abc";
//   char arr2[] ={'a','b','c'};
//   char arr3[] ={'a','b','c','\0'};
//   printf("%s\n",arr1);
//   printf("%s\n",arr2);
//   printf("%s\n",arr3);
//   printf("%d\n",strlen(arr1));
//   printf("%d\n",strlen(arr2));
//   printf("%d\n",strlen(arr3));
  

//   getchar();
//   return 0;
//   }




//选择，试试不对

// #include<stdio.h>
// void swap (int* a,int* b);
// void huan (int a[],int n);
// int main(){
// int a[10]={0,9,8,7,6,5,4,3,2,1,};
// huan(a,10);

// for(int i=0;i<10;i++){
//   printf("%d",*(a+i));
// }
// return 0;

// }
// void swap(int* a,int* b){
//   int t;
//   t=*a;
//   *a=*b;
//   *b=t;
// }
// void huan (int a[],int n){
//   int t;
//   for(int i=1;i<n;i++){
//     while(a[i]<a[i-1]){
//       swap((a+i),(a-i));
//     }
//   }
// }
//水仙花数

// #include<stdio.h>
// int main(){
//   int i=1;
//   for(i=1000;i<10000;i++){
//     int d1=i%10;//个位数
//     int d2=i/10%10;//十位数
//     int d3=i/100%10;//百位数
//     int d4=i/1000%10;
//     int ret=d1*d1*d1+d2*d2*d2+d3*d3*d3+d4*d4*d4;
//     if(ret == i){
//       printf("%d\n",i);
//     }
    
//   }
// return 0;
// }

//桶排序，每个桶冒泡排序
// #include<stdio.h>
// #include<stdlib.h>
// #include<string>

// void leibu(a[]);

// int main(){
//   int a[]
//   return 0;
// }



// void leibu(a[],){

// }

// 快民运算
// // #include<stdio.h>
// int main(){
//   int a=1;
//   int y=8,x=1;
//   while(y){
//     if(y%2!=0) {
//     a*=x;
//     x*=x;
//     y/=2;}}
//     printf("%d",&a);
//     return 0;
  
// }


// #include<stdio.h>
// #include<math.h>

// int main(){
//   int n;
//   scanf("%d",&n);
//   int i,f,p;
//   i=f=pow(10,n-1);
//   while(i<f*10){
//     p=i;
//     int sum=0;
//     while(p!=0){
      
//       int k;
//       k=p%10;
//       p/=10;
//       sum=sum+pow(k,n);

//     }if(sum==i){printf("%d",i);}
//     i++;

//   }
//   return 0;
// }

// include<stdio.h>
// include<math.h>
// int main(void){
// int a,b;
// scanf("%d%d",&a,&b);
// int sum=0;
// for(int i=a; i<=b; i++){
//     for(int j=2;j<(i/2) ;j++ ){
//       if(i%j==0) break;
//       sum++;

//     }

// }continue;
// peintf("%d",sum);
// return 0;
// }


// #include<stdio.h>
// int main(){
//   int a[1];
//   int b[1];
//  int c[2]={0};
//   for(int i=0;i<501;i++){
//     scanf("%1d",a[0]);
//   }
//   for(int i=0;i<501;i++){
//     scanf("%1d",b[0]);
//     }
//     for(int i=0;i<501;i++){
//       c[i]=a[i]+b[i]+c[i];
//       if(c[i]>=10){
//         c[i+1]++;
//         c[i]-=10;
//       }
//     }
//     for(int i=0;i<501;i++){
//     printf("%d",c[i]);}
//     return 0;

// }

//9.11

// #include<stdio.h>
// double min(double m,double n);
// int main(){
//   double m,n;
//   scanf("%lf%lf",&m,&n);
//   printf("%lf",min(m,n)); 
//   return 0;

// }

// double min(double m,double n){
//   double h;
//   if(m>n) h=n;
//   else h=m;
//   return h;
// }


//9.11 2  看不懂题

//9.11 3
// #include<stdio.h>
// void dayin(char a,int i,int j);
// int main(){
//   char b;
//   int i,j;
//   scanf("%c",&b);
//   scanf("%d%d",&i,&j);
//     dayin(b,i,j);
//     return 0;
// }
// void dayin(char a,int i,int j){
//   for(int n=0;n<i;n++){
//     for(int m=0;m<j;m++ ){
//       printf("%c",a);
//     }
//     printf("\n");
//   }
// }



//9.11 4 调和平均数
// #include<stdio.h>
// double tiaohe(double m,double n);

// int main(){
//   double i,j;
//   scanf("%lf%lf",&i,&j);
//   printf("%lf",tiaohe(i,j));

//   return 0;
// }
// double tiaohe(double m,double n){
//   double ret;
//   ret=1/((1/m+1/n)/2);
//   return ret;
// }


//9.11 5
// #include<stdio.h>
// void bianda(double* h,double* g);
// int main(void){
//   double m,n;
//   scanf("%lf%lf",&m,&n);
//   bianda(&m,&n);
//   printf("%lf %lf",m,n);


//   return 0;
// }

// void bianda(double* h,double* g){
//     if(*h>*g) *g=*h;
//     else *h=*g;
 
// }


// 9.11 6

// #include<stdio.h>


// int main(){
  
// }


//高精度加法

// #include<stdio.h>
// #include<string.h>
// char a[500],b[500];
// int c[500],d[500],f[500];
// int max(int a,int b);

// int main(){
// int la,lb,lc;
// scanf("%s",a);
// scanf("%s",b);
// la=strlen(a);//strlen函数，字符串长度；
// lb=strlen(b);
// lc=max(la,lb)+1;
// for(int i=0;i<la ;i++){
//     c[la-i]=a[i]-'0';
// }

//     // for(int i=1 ;i<la+1;i++){
//     //     printf("%d",c[i]);

//     // }
//     // printf("\n");

// for(int i=0 ; i<lb ;i++){
//     d[lb-i]=b[i]-'0';
// }//反转；

//     //     for(int i=1 ;i<lb+1;i++){
//     //     printf("%d",d[i]);


//     // }printf("\n");
// lc=max(la,lb)+1;
// for(int i=0 ;i<lc ;i++){
//     f[i]=c[i]+d[i]+f[i];
//     if(f[i]>=10){
//         f[i+1]=1;
//         f[i]%=10;
//     }}//加法
//     if(f[lc]==0) lc--;
    
//     for(int i=lc ;i>0;i--){
//         printf("%d",f[i]);

//     }
// return 0;
// }

// int max(int a,int b){
//     int c;
//     if(a>b){
//         c=a;
//     }else c=b;

//     return c;
// }


//高精度减法

// #include<stdio.h>
// #include<string.h>
// int max(int a,int b);
// char a[500], b[500];
// int c[500],d[500],f[500]={0};
// int main(void){

// int la,lb,lc;
// scanf("%s",a);
// scanf("%s",b);
// la=strlen(a);
// lb=strlen(b);
// lc=max(la,lb);//长度




// for(int i=0 ;i<la; i++){
// c[la-i]=a[i]-'0';

// }
// for(int i=0 ; i<lb ; i++){
//     d[i]=b[lb-i]-'0';
// }
// //反转；
//         // for(int i=0 ;i<la+1;i++){
//         // printf("%d",d[i]);
//         // }
//         // printf("\n");
//         // for(int i=0 ;i<lb+1;i++){
//         // printf("%d",c[i]);
//         // }
//         // printf("\n");
// for(int i=0 ; i<lc ;i++){
//      f[i]=c[i]-d[i]+f[i];
//      if(f[i]<0){
//         f[i]+=10;
//         f[i+1]=-1;
//      }
//      }
// for(int i=0 ; i<lc ; i++){
//   printf("%d",f[lc-i]);   
// }



// return 0;
// }

// int max(int a,int b){
//     int c;
//     if(a>b) c=a;
//     else c=b;
//     return c;
// }

// //gpt写的
// #include <stdio.h>
// #include <string.h>

// int max(int a, int b);
// void reverse(char str[], int length);
// void subtract(char a[], char b[], int la, int lb);

// char a[500], b[500];
// int c[500], d[500], f[500];

// int main(void) {
//     int la, lb, lc;
//     scanf("%s", a);
//     scanf("%s", b);
//     la = strlen(a);
//     lb = strlen(b);
//     lc = max(la, lb);  // 长度

//     for (int i = 0; i < la; i++) {
//         c[i] = a[la - i - 1] - '0';
//     }
//     for (int i = 0; i < lb; i++) {
//         d[i] = b[lb - i - 1] - '0';
//     }

//     subtract(a, b, la, lb);

//     return 0;
// }

// void subtract(char a[], char b[], int la, int lb) {
//     int borrow = 0;
//     int i;

//     for (i = 0; i < lb; i++) {
//         int diff = c[i] - d[i] - borrow;
//         if (diff < 0) {
//             diff += 10;
//             borrow = 1;
//         } else {
//             borrow = 0;
//         }
//         f[i] = diff;
//     }

//     for (; i < la; i++) {
//         int diff = c[i] - borrow;
//         if (diff < 0) {
//             diff += 10;
//             borrow = 1;
//         } else {
//             borrow = 0;
//         }
//         f[i] = diff;
//     }

//     reverse(f, max(la, lb));

//     // 输出结果
//     for (int i = 0; i < max(la, lb); i++) {
//         printf("%d", f[i]);
//     }
// }

// int max(int a, int b) {
//     return (a > b) ? a : b;
// }

// void reverse(char str[], int length) {
//     int start = 0;
//     int end = length - 1;
//     while (start < end) {
//         int temp = str[start];
//         str[start] = str[end];
//         str[end] = temp;
//         start++;
//         end--;
//     }
// }




//9.11 6
// #include<stdio.h>

// void  swp (double* a,double *b, double * c){
//     double d[3];
//         d[0]=*(a);
//         d[1]=*b;
//         d[2]=*c;
//         for(int i=0;i<2;i++){
//             for(int j=0;j<3-i;j++ ){
//                 double n;
//                 if(d[i]>d[i+1]){
//                     n=d[i];
//                     d[i]=d[i+1];
//                     d[i+1]=n;                }
//             }
//         }
       
//         *a=d[0];
//         *b=d[1];
//         *c=d[2];
//    //   printf("%lf %lf %lf\n",*a,*b,*c);
//      //   printf("%lf %lf %lf\n",d[0],d[1],d[2]);
    
// }

// int main(void){
//     double a=2,b=6,c=5;
//     swp(&a,&b,&c);
//     printf("%lf %lf %lf",a,b,c);
//     return 0;
// }


//9.11 7  看不懂啊



//9.11 8
// #include<stdio.h>
// double jj(double a, int n){
//     double sum=1;
//     if(n==0) return 1;
//     else if(a==0) return 0;
//     else  {
//         for(int i=0; i<n ;i++){
//             sum*=a;
//         }

        
//     }return sum;
// }

// int main(void){
//     double a;
//     int n;
//     scanf("%lf%d",&a,&n);
//     printf("%lf",jj(a,n));
//     return 0;

// }



// //9.11 9
// #include<stdio.h>
// double jj2(double a,int n){
//     double sum=1;
//     if(n ==0) return sum;
//     else if(a==0) return 0;
//     else{

//         sum*=jj2(a,n-1);

    
//     }
// }


// int main(void){
//     double a;
//     int n;
//     scanf("%lf%d",&a,&n);
//     printf("%lf",jj2(a,n));
//     return 0;

// }



//插入排序
// #include<stdio.h>
// void swp(int* a ,int * b);
// int main(){

//     int a[100];
//     int N;
//     scanf("%d",&N);
//     for(int i=0 ;i<N;i++){
//         scanf("%d",&a[i]);
//     }
    
//     for(int i=0 ; i<N ;i++){
        


//     }


//     return 0;
// }

// void swp(int *a ,int * b){
//     int t;
//     t=*a;
// -    *a=*b;
//     *b=t;
// }


// //
// #include<stdio.h>
// int main()
// {
//     int a=1;
//     puts("123"+1);
//     printf("%d\n",50 * * "3");
//     char* d;
//     *d='2';
//     int b=*d;
//     char h ='2';
//     printf("%d\n",b);
//     printf("%p\n",d);
//     printf("%d\n",(int)*d);
//     printf("%p",&h);
//     return 0;
// }



//
// #include<stdio.h>
// int main(){
//     int a=1;
//     float b=1.4;
//     printf("%f\n",b);
//     printf("%lf\n",b);
//     printf("%d %d %d %d ",sizeof(a+b),sizeof(int),sizeof(float),sizeof(double));
//     return 0;
// }


// #include<stdio.h>
// #include<stdlib.h>
// int main(){
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     int (*p1)[10]=&arr;
//     for( int j=0;j<10;j++){
//         printf("%p  ",(*p1+j));
//         printf("%d  ",*(*p1+j));
        
//         printf("%p ",arr+j);
//         printf("\n");
//     }
//     return 0;
// }


//

// #include<stdio.h>
// int main(){
//     float a=21.3;
//     printf("%f",a);
//     return 0;
// }

//插入排序(先打的)
// #include<stdio.h>
// void swp(int * a,int * b);
// int main(void){
//     int arr[10]={9,8,6,4,7,3,5,3,2,6};
//     for(int i=1 ;i<10 ;i++){
//         for(int j =i,k=i;j>0 ;j--){
//             if(arr[k]<arr[j-1]){
//                 swp(arr+k ,arr+j-1);
//                 k--;
//             }
//             else break;
//         }
//     }
// for(int i=0; i<10 ; i++){
//     printf("%d  ",arr[i]);
// }
// return 0;    


// }

//插入排序教程

// #include<stdio.h>
// void paixu(int * arr ,int n);
// int main(){
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     paixu(arr,10);
//     return 0;
//     for(int i=0; i<10 ; i++){
        
// printf("%d  ",arr[i]);
//     }
//     return 0;


// }

// void paixu(int * arr,int n){
//     for(int i=0 ;i<n-1 ;i++){
//         //记录有序排列的最后一个元素下标
//         int end =i;
//         int tem=arr[end+1];
//         while(end >=0){
//         if(tem<arr[end]){
//             arr[end +1] =arr[end];
//         end--;
//         }
//         else break;

//         }

//     }

// }




// void swp(int * a ,int *b){
//     int t =*a;
//     *a=*b;
//     *b =t ;
// }

//希尔排序，希儿好可爱#-#；
// #include<stdio.h>
// void arr_out(int *arr);
// void arr_sort(int * arr, int n);
// int main(void){
//     int  arr[8]={9,8,4,7,5,3,2,6};
//     int gap=8;
   
//     arr_sort(arr,gap);
//      arr_out(arr);
// return 0; 
//}

// void arr_out (int *arr){
//     for(int i=0 ; i<8 ;i++){
//         printf("%d ",arr[i]);
//     }
// }
// void arr_sort(int *arr, int n){
//     int step=0;
//     int temp=0;

//     int i,j ;
//     for(step = n/2 ;step >0 ; step/=2){
//         for(i=step ;i < n ;i++){
//             temp=arr[i];
//             for(j =i-step ;j >=0 && arr[j]> temp ;j-=step)
//             {
//                 arr[j+step] = arr[j];
//             }
//             arr[j+step] =temp;

//         }
//     }

// }

//写一遍；
// #include<stdio.h>
// int main(){
//     int arr[10] ={3,4,6,7,4,5,2,5,7,8};
//     int step =0;
//     int temp =0;
//     int j, i;
//         int n=10;
//         for(step =n/2 ; step >0 ;step/=2){
//             for(i=step ; i< n ; i++){
//         temp=arr[i];
//         for( j= i-step ;j >= 0 && arr[j] > temp ; j-=step ){
//                 arr[j+step]=arr[j];

//         }
//         arr[j+step] = temp;
//         }
        
//         }

// for(int i=0 ;i <10 ; i++){
//     printf("%d ",arr[i]);
// }
// return 0;

// }

//快速排序 1;

// #include<stdio.h>
// void swp(int *a ,int *b);
// int main()
// {
//     int arr[10]={13,4,9,0,70,11,5,6,8,10};

//     int n=10;
//     int text =arr[0];
//     int i,j;
    
//     for(int k=0 ;k <10 ;k++){
//     for( int i=10 ;i >=0 ;i--)
// {
//     if(arr[i]> text){
//      break;
//      }
// }  
// for( int  j=1 ;j<10 ;j++)
// {
//     if(arr[j]< text){
//      break;
//      }
// }
// swp(arr+i ,arr+j);
// if(i==j) {
//     swp(arr,&arr[i]);
//     break;
// }

// }
// for(int k=0 ; k<10 ; k++){
//     printf("%d  ",arr[k]);
// }
// printf("\n%d %d",i,j);
// return 0;

// }

// void swp(int *a ,int *b){
//     int t= *b;
//     *b =*a;
//     *a =t;
// }

//10.7 快速排序，高精度乘法

// #include<stdio.h>
// #include<stdio.h>
// int a=3;
// int aa(){
   
//    int h= main(2,3,4);
//     printf("%d",h);
//     return 2;

// }

// int main(int b,int c,int d){
//  if(a==2){system("pause");}
// printf("%d %d",aa(),--a);


// return 0;

// }


//快速排序1.1
// #include<stdio.h>
// void swp(int *a ,int *b);
// void shuchu(int a[],int n);
// int main(){
//     int  a[10]={9,3,7,5,6,2,4,1,0,8};
//     int t=a[0];
//     int i=0,j=9;
//     while(i==j){
//         while(!a[i]>t){
//             i++;
//         }
//         while(!a[j]<t){
//             j--;
//         }
//         swp(&a[i],&a[j]);

//          for(int i=0 ;i<10 ; i++){
//         printf("%d",a[i]);
//     }

//     return 0;

//     }


// }
// void shuchu(int a[],int n){
//     for(int i=0 ;i<n ; i++){
//         printf("%d",a[i]);
//     }

//}
// void swp(int *a ,int *b){
//     int t= *b;
//     *b =*a;
//     *a =t;
// }


// #include<stdio.h>
//  int a;
// int main(int argc, char *argv[]){
   
//     printf("%d\n",argc);
//     for(int i=0 ; i<argc ; i++){
//         printf("%s\n",argv[i]);
//     }
//     return 0;
// }


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

// #define swp(a,b) do(a^=b; b^=a; a^=b )while(0)

// #include<stdio.h>
// int main(){
//     int h=10;
//     int n=5;
//     printf("%d %d",h,n);

// return 0;
// }//



// #include<stdio.h>
// #include<stdbool.h>
// int main(){
//     int intvar;
//     scanf("%d",&intvar);
//     bool boolvar =intvar;
//     int result =boolvar;
//     printf("%d\n",result);
//     return 0;
// }
#include<stdio.h>
int main(){
    int n;
    printf("%d",scanf("%d",&n));

return 0;
}
