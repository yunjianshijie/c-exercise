//9.11 3
#include<stdio.h>
void dayin(char a,int i,int j);
int main(){
  char b;
  int i,j;
  scanf("%c",&b);
  scanf("%d%d",&i,&j);
    dayin(b,i,j);
    return 0;
}
void dayin(char a,int i,int j){
  for(int n=0;n<i;n++){
    for(int m=0;m<j;m++ ){
      printf("%c",a);
    }
    printf("\n");
  }
}
