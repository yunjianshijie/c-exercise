
#include<stdio.h>
struct ListNode {
     int val;
     struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
        struct ListNode *a=( struct ListNode *)malloc(sizeof(struct ListNode  ));
         struct ListNode *b;//=( struct ListNode *)malloc(sizeof( struct ListNode ));
         struct ListNode *d;//=( struct ListNode *)malloc(sizeof( struct ListNode ));
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if(list1->val>list2->val){
            d=a=list2 ; b=list1 ;  
        }else {d=a=list1 ; b=list2 ;}

//将a指向第一个数大的链表
 if(a->next == NULL){
     a->next =b;
     return a;
 }else {    
     while(a!=NULL&b!=NULL){
      if((a->next)==NULL){
        a->next=b;
        return d;
    }

      if((b->next)==NULL){
        return d;
    }
     if(a->val<=b->val) {
         a=a->next;
     }else { 
        struct ListNode *c=(struct ListNode *)malloc(sizeof(struct ListNode));
        c->val=b->val;
        c->next=a->next;
        a->next=c;
        b=b->next;
     }
 
  }
 }
return d;
}

int main(){
    static ListNode *A; 
    


}