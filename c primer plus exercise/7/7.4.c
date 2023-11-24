#include<stdio.h>
#include<stdlib.h>

int main(){
char a,b='0';

int count=0;

while((a=getchar())!="#" && b!='#'){
    
    if(a=='!' && b!='!') {count++;}
    b=a;
}
printf("\n%d",count);
return 0;

}