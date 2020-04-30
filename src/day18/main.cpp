#include<stdio.h>
#include <malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
typedef  struct  ListNode * ListLink;
ListLink intersection(ListLink l1, ListLink l2){
    //1.头节点
    ListNode dummy;
    //2.取交集
    ListLink p=&dummy;
    while(l1!=NULL&&l2!=NULL){
       if(l1->val<l2->val){//l1落后
           l1=l1->next;
       } else if(l1->val>l2->val){//l2落后
           l2=l2->next;
       }else{//找到值相同的位置 进行复制
           p->next=(ListLink)malloc(sizeof(ListNode));
           p=p->next;
           p->val=l1->val;
           l1=l1->next;
           l2=l2->next;
       }
    }
    p->next=NULL;
    return dummy.next;
}