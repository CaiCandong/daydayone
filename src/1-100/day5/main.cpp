#include <stdio.h>
#include <malloc.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListLink;

//插入排序
ListLink *insertionSortList(ListLink *head)
{
    // ListLink dummy;
    // dummy.next = head;
    // dummy.val = -2147483648;
    ListLink dummy = {1 << 31, head};
    ListLink *precede = head; //指向待插入节点
    ListLink *tail = &dummy;  //完成排序链表的尾部
    ListLink *p;              //用于寻找插入位置指针
    while (precede != NULL)
    {
        if (precede->val >= tail->val)
        {
            //无需执行插入
            tail = tail->next;
            precede = precede->next;
            continue;
        }
        //寻找插入位置
        p = &dummy;
        for (; p->next->val < precede->val; p = p->next)
            ;
        // 执行插入
        tail->next = precede->next;
        precede->next = p->next;
        p->next = precede;
        precede = tail->next;
    }
    return dummy.next;
}
int main()
{
    int a = 1 << 31;
    printf("%d", a);
}
