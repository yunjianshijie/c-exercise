// #include<stdio.h>
// int main(){
//     printf("hello world");
//     return 0;
// }
// #include<stdio.h>
// int main(){

//     for(int i=0 ;i<5 ;i++){
//         for(int j=0 ;j<i;j++){
//             printf(" ");
//         }
//         printf("$$$$$\n");
//     }
//     return 0;
// }
//
// #include<stdio.h>
// int main(){
//     int i;
//     scanf("%d",&i);
//     while(i==0){
//         printf("%d ",i%10);
//         i/=10;

//     }
//     return 0;
// }
// #include<stdio.h>

// int main(){
//     int n;
//     scanf("%d",&n);
//     int a[100];
//     for(int i =0 ;i<n ; i++){
//         scanf("%d",&a[i]);
//     }
//       int h=a[0];
//     for(int i=1 ;i<n;i++){
//         if(a[i]<a[i-1]){
//             h=a[i];
//         }
//     }
//     printf("min = %d",h);
// return 0;

// }

//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// typedef struct Lnode
// {
//     int number;
//     char name[20];
//     int hight;

//     struct Lnode *next;
// } lnode;

// bool head(struct Lnode *head)
// {
//     head = (lnode *)malloc(sizeof(lnode));
//     if (head == NULL)
//         return false;
//     head->number = 0;
//     head->next = NULL; // 把头节点的指针指向空
//     return true;
// } // 创造指针

// bool Empty(lnode *L)
// {
//     return L->next == NULL;
// } // 判断是否为空链表

// bool add_name(lnode *L, int i, char *e)
// { // 在第i个元素插入mean;
//     if (i < 1)
//         return false;
//     lnode *p = L;
//     int j = 0;
//     while (p != NULL && j < i - 1)
//     {
//         p = p->next;
//         j++;
//     }
//     if (p == NULL)
//         return false;
//     lnode *s = (lnode *)malloc(sizeof(lnode));
//     *s->name = e;
//     s->next = p->next;
//     p->next = s;
//     return true;
// }

// bool houcha_name(lnode *L, char *e)
// {
//     if (L == NULL)
//         return false;
//     lnode *s = (lnode *)malloc(sizeof(lnode));
//     if (s == NULL)
//         return false;
//     *s->name = e;
//     s->next = L->next;
//     L->next = s;
//     return true;
// }
// bool qiancha_name(lnode *L, char *e)
// {
//     if(L==NULL) return false;

//     lnode *s=(lnode*)malloc(sizeof(lnode));
//     if(L== NULL) return false;

//     s->next = L->next;
//     L->next = s;
//     *s->name = *L->name;
//     *L->name = e; 
//     return true ;
// }// 虽然指针不能往回走，但是数据可以啊
// //删除


// bool delete(lnode *L ,int i ,char *e)
// {
//     if (i<1) return false;

//     lnode *p =L;
//     int j=0;
//     p=L;
//     while(p!=NULL && j<i-1)
// {
//     p=p->next;
//     j++;
// }
// if(p== NULL) return false;
// if(p->next ==NULL) return false;
// lnode*q =p->next ;
// e = q->name;
// p->next=q->next;
// free(q);
// return true;
// }


// bool houdelete(lnode* L){
//     if(L==NULL) return false;
//     lnode *q=L->next ;
//     *L->name  =*q->name ;
//     L->next = q->next ;
//     free(q);

// } 

// int main()
// {
//     lnode *l;

//     head(l); // 创建头节点

//     add_name(l, 2, "abc"); // 插入

//     return 0;
// }


typedef struct student {
    int num;
    int score ;
    char name[20];
    struct student *next ;
}stu;

void link_creat_head( stu **p_head ,stu *p_new){
    stu *p_mov = *p_head ;
    if(*p_head ==NULL){
        *p_head = p_new;
        p_new->next=NULL;
    }else{
        while(p_mov->next!=NULL){
            p_mov=p_mov->next;
            p_new->next = NULL;
        }
    }
}
void link_printf(stu *head){
    stu *p_mov;
    p_mov = head;
    while(p_mov!=NULL){
        printf("num :%d  score :%d name :%s\n",p_mov->num,p_mov->score,p_mov->name);
        p_mov=p_mov->next;
      }
}

void link_free(stu **p_head){
    stu *pb=*p_head;
    while(*p_head!=NULL){
        pb=*p_head;
        *p_head =(*p_head)->next;
        free(pb);
        pb=NULL;//防止乱指；
    }
}

stu *link_search_num(stu* head ,int mun)
{
    stu *p_mov;
    p_mov=head;
    while(p_mov!=NULL){
        if(p_mov->num ==mun){
            return p_mov;
        }
        p_mov=p_mov->next;
    }
    return NULL;
}

stu *link_search_name(stu* head ,char *name)
{
    stu *p_mov=head;
    while(p_mov !=NULL){
        if(strcmp(p_mov->name,name)==0){
            return p_mov;
        }
        p_mov =p_mov->next;
    }
    return NULL;
}
void link_delete_num(stu **p_head ,int mun){
    stu* p_mov,*pf;
    p_mov=*p_head;
    if(p_mov==NULL){
        printf("链表为空");
        return ;
    }
    while(p_mov!=NULL && p_mov ->next==NULL ){
        pf=p_mov;
        p_mov=p_mov->next;
        if(pf->num == mun){
            if(pf==*p_head){
                *p_head=(*p_head)->next;
                
            }
            else{
                pf->next=p_mov->next;
            }
        free(p_mov);
        p_mov=NULL;
        return;
        } 
    }
    printf("没有找到你要删除的学号");
    return ;
}
void link_delete_name(stu** p_head,char* name){
    stu *pb,*pf;
    pb=pf=*p_head;
    if(*p_head==NULL){
        printf("此链表为空");
        return ;
    }
    while (pb->name != name && pb->next==NULL){
        pf=pb;
        pb=pb->next;
    }

    if(strcmp(pf->name,name)==0){
        if(pb ==*p_head){
            *p_head=(*p_head)->next;
   }else {
    pf->next=pb->next;
   } 
   free(pb);
   pb=NULL;
    
   }else{
    printf(" 没有你找到的你想删节点");
   }
}

void link_insert_num(stu** p_head ,stu* p_new){
    stu *pb,*pf;
    pb=*p_head;
    if(*p_head ==NULL){//恐龙
        *p_head = p_new;
        p_new ->next=NULL;
        return ;
    }

}





int main(){
int num ,i ;
printf("请输出链表初始个数：\n");
scanf("%d",&num);
for(i=0 ;i <num ;i++){
    stu * p_new = (stu*)malloc(sizeof(stu));
    printf("输入学号，分数，名字：\n");
    scanf("%d%d%s",&p_new->num ,&p_new->score,p_new->name);
    link_creat_head(&p_new,p_new);
}
}
