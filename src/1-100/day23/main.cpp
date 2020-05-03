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
    int dx;
    if(root->left==NULL&&root->right==NULL){
        dx=0;
    }else if(root->left==NULL||root->right==NULL){
        dx=1;
    }else{
        dx=0;
    }
    return dx+countNodes(root->left)+countNodes(root->right);
}
