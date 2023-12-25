// #include <stdio.h>
// #include <stdlib.h>
// struct ss {
//     int val;
//     struct ss* next;
// };
// int main() {
//     int h = 0;
//     scanf("%d", &h);
//     struct ss head;
//     struct ss* a = &head;
//     while (h != -1) {
//         struct ss* hall = (struct ss*)malloc(sizeof(struct ss));
//         a->next = hall;
//         hall->val = h;
//         a = a->next;
//         scanf("%d", &h);
//     }
//     a->next = NULL;
//     a = &head;
//     while (a->next != NULL) {
//         a = a->next;
//         printf("--%d", a->val);
//     }  // 打印第一个
//     printf("\n");
//     struct ss* b = &head;
//     struct ss* c = &head;
//     a = &head;
//     b = b->next;
//     c = b->next;
//     while (c != NULL) {
//         b->next = a;
//         a = b;
//         b = c;
//         c = c->next;
//     }
//     b->next = a;
//     int count = 0;
//     head.next = NULL;
//     while (b->next != NULL && b->val != -1 && count < 50) {
//         printf("--%d", b->val);
//         b = b->next;
//         count++;
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // 定义单链表节点结构体
// struct ListNode {
//     int val;
//     struct ListNode* next;
// };

// // 合并单链表LA和LB，并返回合并后的单链表LC
// struct ListNode* mergeLists(struct ListNode* LA, struct ListNode* LB) {
//     struct ListNode dummy;  // 虚拟头节点
//     struct ListNode* LC = &dummy;

//     struct ListNode* curA = LA;
//     struct ListNode* curB = LB;

//     while (curA != NULL && curB != NULL) {
//         LC->next = curA;
//         curA = curA->next;
//         LC = LC->next;

//         LC->next = curB;
//         curB = curB->next;
//         LC = LC->next;
//     }

//     if (curA != NULL) {
//         LC->next = curA;
//     } else {
//         LC->next = curB;
//     }

//     return dummy.next;
// }

// // 创建单链表
// struct ListNode* createList() {
//     struct ListNode* head = NULL;
//     struct ListNode* tail = NULL;

//     int num;
//     while (scanf("%d", &num) == 1 && num != -1) {
//         struct ListNode* newNode =
//             (struct ListNode*)malloc(sizeof(struct ListNode));
//         newNode->val = num;
//         newNode->next = NULL;

//         if (head == NULL) {
//             head = newNode;
//             tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = tail->next;
//         }
//     }

//     return head;
// }

// // 打印单链表
// void printList(struct ListNode* head) {
//     struct ListNode* cur = head;
//     while (cur != NULL) {
//         printf("--%d", cur->val);
//         cur = cur->next;
//     }
//     printf("\n");
// }

// // 释放单链表的内存
// void freeList(struct ListNode* head) {
//     struct ListNode* cur = head;
//     while (cur != NULL) {
//         struct ListNode* temp = cur;
//         cur = cur->next;
//         free(temp);
//     }
// }

// int main() {
//     struct ListNode* LA = createList();
//     struct ListNode* LB = createList();

//     // 合并单链表LA和LB得到LC
//     struct ListNode* LC = mergeLists(LA, LB);

//     // 输出合并后的单链表LC的数据结果
//     printList(LC);

//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int n;
//     scanf("%d", &n);
//     int max, min;
//     int d;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &d);
//         if (i == 0) {
//             max = d;
//             min = 0;
//         }
//         if (max < d) {
//             min = max;
//             max = d;
//         } else if (min <= d && max != d) {
//             min = d;
//         }
//     }

//     printf("%d %d", max, min);
// }

#include <stdio.h>
int main() {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    s++;
    if (s >= 60) {
        m++;
        s -= 60;
        if (m == 60) {
            h++;
            m -= 60;
            if (h == 24) {
                h = 0;
                m = 0;
                s = 0;
            }
        }
    }
    printf("%02d:%02d:%02d", h, m, s);
}