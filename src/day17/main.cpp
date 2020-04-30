#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode *ListLink;

/*
 * length代表等待操作的长度
 * head为首地址指针
 */
ListLink helper(ListLink head, int length) {
    //1.节点数目为奇数,中心为1个节点
    if (length == 1) {
        ListLink ret = head->next;
        head->next = NULL;
        return ret;
    }
    //2.节点数目为奇数,中心为2个节点
    if (length == 2) {
        ListLink ret = head->next->next;
        head->next->next = NULL;
        return ret;
    }
    //3.获取等待合并的节点tail
    ListLink tail=helper(head->next,length-2);
    ListLink ret=tail->next;
    ListLink temp=head->next;
    head->next=tail;
    tail->next=temp;
    return ret;
}

void reorderList(ListLink head) {
    //1.获取长度
    ListLink p = head;
    int length = 0;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    //2.特殊判断
    if (length < 3) {//3个一下节点不需要操作
        return;
    }
    //3.进入递归
    helper(head, length);
}


int main() {
    return 0;
}