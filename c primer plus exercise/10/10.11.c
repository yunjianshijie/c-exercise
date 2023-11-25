#include<stdio.h>
#include<stdlib.h>


void prin(double a[3][5]);
void jianei(double a[3][5]);
void prin(double a[3][5]){
    for(int i=0 ;i<3 ;i++){
        for(int j=0 ;j<5 ;j++){
            printf("%.2lf ",a[i][j]);
        }
    printf("\n");
    }
}


void jianei(double a[3][5]){
        for(int i=0 ;i<3 ;i++){
        for(int j=0 ;j<5 ;j++){
        a[i][j]*=2;
        }
    }


}

int main(){
    
double a[3][5]={2,2,56,6,5,3,5,8,6,};
prin(a);
jianei(a);
prin(a);
return 0;
}

