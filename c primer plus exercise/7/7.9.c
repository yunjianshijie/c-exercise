#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int shush(int n)
{
    for(int i=2 ;i<n/2 ;i++){
        if(n%i==0){
            return 0;
        }
    }
return 1;

}
void dayin(int n){
    for(int i=2 ;i<=n ;i++)
    {
        if(shush(i)) printf("%d ",i);
    }
    return ;
}

int main(){
int n=423;
    dayin(n);
    return 0;

}