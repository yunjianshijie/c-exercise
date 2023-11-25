 #include<stdio.h>
#include"names_st.h"

void get_name(names *pn){
    printf("输入你 first name:");
    s_gets(pn->first ,slen);
    printf("\n输入你的 last name:");
    s_gets(pn->last,slen);

}
void show_names(const names *pn){
printf("%s %s",pn->first,pn->last);
}
char * s_gets(char * st ,int n){
    for(int i =0 ;i<n ;i++)
{
    



}

}