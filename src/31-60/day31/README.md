## 每日一道编程题（13）：华科834/887

**2017华科计院**

假设带头结点的单链表A，B为有序递增表，单链表的类型定义如下：

Typedef struct LNode

{ Element Type data;

Struct LNode *next;

}LNode, *LinkList;

编写算法voidDelete（LinkList *A,LinkList *B）

**从有序表 A 中删除所有和有序表 B 中元素相同的结点。**



``` c
#include <stdio.h>
#include <malloc.h>

//A-B
typedef struct Node {
    int val;
    struct Node *next;
} LNode, *LinkList;

//数组转链表 带头结点
LinkList array2link(int *array, int length) {
    //头节点
    LinkList head = (LinkList) malloc(sizeof(LNode));
    head->next = NULL;
    LinkList p = head;
    for (int i = 0; i < length; i++) {
        p->next = (LinkList) malloc(sizeof(LNode));
        p = p->next;
        p->val = array[i];
    }
    p->next = NULL;
    return head;
}

// 遍历链表
void trave(LinkList head) {
    LinkList p = head->next;
    while (p != NULL) {
        printf("%d ", p->val);
        p=p->next;
    }
    printf("\n");
}

void Delete(LinkList A, LinkList B) {
    LinkList p = A, q = B, temp = NULL;
    while (p->next != NULL && q->next != NULL) {
        //1.p.val<q.val
        if (p->next->val < q->next->val) {
            p = p->next;
        } else if (p->next->val > q->next->val) {
            q = q->next;
        } else {
            temp = p->next;
            p->next = p->next->next;
            free(temp);
            q = q->next;
        }
    }
}

int main() {
    int array1[]={1,2,3,4,5,6,7};
    int array2[]={1,2,3,4,5,6};
    LinkList  list1=array2link(array1,7);
    LinkList  list2=array2link(array2,6);
    Delete(list1,list2);
    trave(list1);
}



```

