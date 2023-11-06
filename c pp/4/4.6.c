//4.8.6
#include<stdio.h>
#include<string.h>
int main(){
    char a[100],b[100];
    scanf("%s %s",a,b);
    int m,n;
    m=strlen(a);
    n=strlen(b);
    for(int i=0 ;i<m-1;i++){
        printf(" ");
    }
    printf("%d",n);
    for(int i=0 ;i<n;i++){
        printf(" ");
    }
    printf("%d",n);
}
