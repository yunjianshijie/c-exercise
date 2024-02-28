#include<signal.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h> 
 void sigHangdler(int sig)
{   
    printf("dhsfj\n");
    //exit(1);
}

int main(){
    int j;
    if(signal(SIGINT,sigHangdler) ==SIG_ERR){
        //在传入SIGINT 信号的时候，进入sigHangdler函数
        exit(1);
    }
    pause();
    for(j=0;;j++){
        printf("%d\n",j);
        printf("hhhhhhh\n");
        sleep(1);
        
    }
}