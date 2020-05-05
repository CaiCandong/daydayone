#include <stdio.h>
#include <malloc.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
typedef struct TreeNode *BiTree;

int maxDepth(BiTree root){
    //非递归写法
    //循环队列
    int length=100;
    BiTree queue[length];
    int top=0,tail=0;

    int ret=-1;
    queue[top++]=root;
    while(top!=tail){
    //1.全部出队列
        int lastTop=top;
        while(tail!=lastTop){
            BiTree temp=queue[tail];
            tail=(tail+1)%length;
            if(temp!=NULL){
                queue[top]=temp->left;
                top=(top+1)%length;
                queue[top]=temp->right;
                top=(top+1)%length;
            }
        }
       ret++;
    }
    return ret;
}