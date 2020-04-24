#include <stdio.h>
#include <malloc.h>
struct ListNode
{
    int val;
    struct ListNode *next;
} ListLink;
typedef struct ListNode ListLink;

// 归并排序
ListLink *sortList(ListLink *head)
{
    //1.递归终止条件,链表少于2个节点
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //2.链表划分,快慢指针实现
    ListLink *precede = head->next, *behind = head;
    while (precede != NULL && precede->next != NULL)
    {
        precede = precede->next->next;
        behind = behind->next;
    }
    //3.分治子问题
    ListLink *temp = behind->next;
    behind->next = NULL;
    head = sortList(head);
    behind = sortList(temp);
    //4.合并子问题
    ListLink ret;
    ListLink *p = &ret;
    while (head != NULL && behind != NULL)
    {
        if (head->val < behind->val)
        {
            p->next = head;
            head = head->next;
        }
        else
        {
            p->next = behind;
            behind = behind->next;
        }
        p = p->next;
    }
    if (head != NULL)
    {
        p->next = head;
    }
    if (behind != NULL)
    {
        p->next = behind;
    }
    return ret.next;
}
int main()
{
}
