#### [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

``` c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode,*TreeLink;
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    //递归算法
    if(preorderSize<=0){
        return NULL;
    }
    //1.寻找树根  前序的第一个结点为树根
    TreeLink root=(TreeLink)malloc(sizeof(TreeNode));
    root->val=preorder[0];
    int i;
    for(i=0;i<inorderSize&&inorder[i]!=root->val;i++);
    //2.切分数组
    root->left=buildTree(preorder+1,i,inorder,i);
    root->right=buildTree(preorder+i+1,preorderSize-i-1,inorder+i+1,inorderSize-i-1);
    return root;
}
```

