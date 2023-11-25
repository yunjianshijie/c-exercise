#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int mpow(int n){
    int ret=1;
    for(int i=0 ;i<n ;i++){
        ret*=2;
    }
    return ret;
}
int shiwei (char *a){
        int b[20]={0};
        
        for(int i =0  ; i< strlen(a) ;i++){
            b[i]=*(a-i+strlen(a)-1)-'0';
        }
    int ret=0;
    for(int i=0 ;i<9 ;i++)
{
    printf("%d",b[i]);

}   
 for(int i =0 ;i<strlen(a);i++){
        ret +=b[i]*mpow(i);
    }
    return ret;


}

int main(){
    char * pbin ="01001001";
     
        printf("%d",shiwei(pbin));
        return 0;


}

