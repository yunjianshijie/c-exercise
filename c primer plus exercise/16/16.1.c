 #include<stdio.h>
 #define Xa(a) x ## a
 int main(){
    int Xa(1) = 2;
    printf("%d",x1);
    return 0;
 }// #include<stdio.h>
// // int main(){
// //     int a[20];
// //     int n;
// //     scanf("%d",&n);
// //     for(int i=0 ;i <n ;i++){
// //         scanf("%d,",&a[i]);
// //        // if(i<n-1) scanf(",");
// //     }
// //     int m=a[0];
// //     for(int i=0 ;i<n ;i++) {
// //         printf("%d",a[i]);
// //     }
// //     for(int i=1 ;i < n ;i++){
// //         if(m<a[i]) m=a[i];
// //     }
   
// //     int h=a[0];
// //     if(m==a[0]) h=a[1]; 
// //     for(int i=0 ;i <n ;i++ ){
// //         if(h<a[i] && a[i] !=m) h=a[i]; 
// //     }
// //     printf("%d,%d",m,h);
// // }



// // #include<stdio.h>

// // int main(){
// //     int n;
// //     scanf("%d",&n);
// //     int a[20];
// //     for(int i=0 ;i<n ;i++)
// // {
// //     scanf("%d,",&a[i]);
// // }
// // int b[20];
// // for(int i =0 ; i<n ;i++){
// //     b[i] =a[n-i-1];
// // }
// // for(int i=0 ;i<n ;i++){
// //     printf("%d",b[i]);
// //     if(i<n-1) prinf(",");
// // }
// // return 0;
// // }



// #include<stdio.h>
// void paixu (int a[],int n){
//     for(int i=0 ;i<n ;i++){
//         for(int j=0 ;j<n-i ;j++){
//             if(a[j]>a[j+1]){
//                 int t=a[j];
//                 a[j]=a[j+1];
//                 a[j+1]=t;
//             }
//         }
//     }
// }

// int shu(int i){
//     int ret =1;
//     for(int u=2 ;u<i/2+1 ;u++){
//         if(i%u==0) {ret=0; break; }
//     }
// return ret;
// }


// int main(){

//     int a[10];
//     for(int i=0 ;i<10 ;i++)
// {
//     scanf("%d,",&a[i]);
// }
//     int r=0;
//     int b[10];
// int count=0;
//     // for(int i=0 ;i<10 ;i++) {
//     //     printf("%d",a[i]);
//     // }
//     for(int i=0 ;i<10;i++){
//         if(shu(a[i])) {r=1; b[count]=a[i]; count++;}
//     }
//     if(r){
//         paixu(b,count+1);
// for(int i=0 ;i<count+1 ;i++){
//     printf("%d",b[i]);
//     if(i<count) printf(",");
// }}
// else  printf("Not found!");
// return 0;

// }
// }

// int shu(int i){
//     int ret =1;
//     for(int u=2 ;u<i/2+1 ;u++){
//         if(i%u==0) {ret=0; break; }
//     }
// return ret;
// }


// int main(){

//     int a[10];
//     for(int i=0 ;i<10 ;i++)
// {
//     scanf("%d,",&a[i]);
// }
//     int r=0;
//     int b[10];
// int count=0;
//     // for(int i=0 ;i<10 ;i++) {
//     //     printf("%d",a[i]);
//     // }
//     for(int i=0 ;i<10;i++){
//         if(shu(a[i])) {r=1; b[count]=a[i]; count++;}
//     }
//     if(r){
//         paixu(b,count+1);
// for(int i=0 ;i<count+1 ;i++){
//     printf("%d",b[i]);
//     if(i<count) printf(",");
// }}
// else  printf("Not found!");
// return 0;

// }