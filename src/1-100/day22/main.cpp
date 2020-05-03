#include<stdio.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
int countNodes(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int dx=0;
    if(root->left!=NULL&&root->right!=NULL){
        dx=1;
    }
    return dx+countNodes(root->left)+countNodes(root->right);
}