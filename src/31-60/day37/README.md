#### [25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

``` c
#include <stdio.h>
#include <malloc.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };

typedef struct ListNode *ListLink;
struct ListNode* reverseKGroup(ListLink head, int k){
    if(k==1){
        return head;
    }
    //0.增加一个头节点
    struct ListNode dummy;
    dummy.next=head;
    //1.统计长度
    ListLink p=&dummy;
    int length=0;
    for(;p->next!=NULL;p=p->next)length++;
    printf("%d",length);
    //2.进行反转
    p=&dummy;
    ListLink q;
    ListLink tail;
    ListLink temp;
    while(length>=k){
        tail=p->next;
        q=p->next->next;
        //头插法 q负责移动
        for(int i=0;i<k-1;i++){
            temp=q->next;
            q->next=p->next;
            p->next=q;
            q=temp;
        }
        tail->next=q;
        p=tail;
        length-=k;
    }
    return dummy.next;
}
ListLink array2link(int *array, int length) {
    //头节点
    ListLink  head = (ListLink) malloc(sizeof(struct ListNode));
    head->next = NULL;
    ListLink p = head;
    for (int i = 0; i < length; i++) {
        p->next = (ListLink) malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = array[i];
    }
    p->next = NULL;
    return head->next;
}
int main(){
    int array[5]={1,2,3,4,5};
    int k=2;
    ListLink head= array2link(array,5);
    reverseKGroup(head,k);
}

```

