
//10.13
#include<stdio.h>
#include<stdlib.h>
void shuru ( double arr[3][5]){
    for(int i=0 ;i<3 ;i++){
    for(int j=0 ;j<5 ;j++){
        scanf("%lf",&arr[i][j]);
    }}}


double * pinjun(double arr[3][5])

{   double *a=(double *)malloc(sizeof(double)*3);
    double ab[3];
    a=ab;
    for(int i=0 ;i< 3 ;i++){
        for(int j=0 ;j<3 ;j++){
        ab[i] += arr[i][j];
        }
        ab[i]/=5;;
    }

return a;
}
int main(){
double a[3][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
//shuru(a);
pinjun(a);
 for(int i=0 ;i<3 ;i++){
    for(int j=0 ;j<5 ;j++){
        printf("%lf",a[i][j]);
    }}
free(a);
return 0;    

}
