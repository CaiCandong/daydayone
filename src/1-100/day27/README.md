#### [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

``` c
#include <stdio.h>
#include <malloc.h>
/**
 * 动手写一个二叉排序树
 */

//1.节点定义
typedef struct Node {
    int Val;
    struct Node *Left, *Right;
} BiNode, *BiLink;
typedef struct BinarySortTree {
    BiNode root;//头节点 只使用右指针
    int length;//记录数中节点的数量
} BST;

//2.插入函数
bool insert(BiLink root, int val);

bool Insert(BST *that, int val);

//3.构造函数
BST NewBST(int *nums, int length);

//4.遍历函数
void preTravel(BiLink root);

void PreTravel(BST that);

//5.删除函数
bool Del(BST *that, int val);

bool del(BiLink root, BiLink parent, int val, bool flag);

bool Insert(BST *that, int val) {
    that->length++;
    BiLink head = &that->root;
    if (head->Right == NULL) {
        head->Right = (BiLink) malloc(sizeof(BiNode));
        head->Right->Right = NULL;
        head->Right->Left = NULL;
        head->Right->Val = val;
        return true;
    } else {
        return insert(head->Right, val);
    }
}

bool insert(BiLink root, int val) {
    if (val < root->Val && root->Left == NULL) {
        root->Left = (BiLink) malloc(sizeof(BiNode));
        root->Left->Val = val;
        root->Left->Left = NULL;
        root->Left->Right = NULL;
        return true;
    } else if (val >= root->Val && root->Right == NULL) {
        root->Right = (BiLink) malloc(sizeof(BiNode));
        root->Right->Val = val;
        root->Right->Left = NULL;
        root->Right->Right = NULL;
        return true;
    }
    //递归部分
    if (val < root->Val) {
        return insert(root->Left, val);
    } else {
        return insert(root->Right, val);
    }
}

bool Del(BST *that, int val) {
    BiLink head = &that->root;
    //1.空树无法删除
    if (head->Right == NULL) {
        return false;
    }
    //2.执行递归删除
    del(that->root.Right, head, val, true);
}

//flag true 代表root是parent的右子树
bool del(BiLink root, BiLink parent, int val, bool flag) {
    //0.未找到
    if (root == NULL) {
        return false;
    }
    //1.删除叶子节点
    if (root->Val == val && root->Left == NULL && root->Right == NULL) {
        if (flag) {//右子树
            parent->Right = NULL;
        } else {//左子树
            parent->Left = NULL;
        }
        free(root);
        return true;
    }
    //2.删除节点只有左子树
    if (root->Val == val && root->Left != NULL) {
        if (flag) {//右子树
            parent->Right = root->Left;
        } else {//左子树
            parent->Left = root->Left;
        }
        return true;

    }
    //3.删除节点有右子树
    if (root->Val == val && root->Right != NULL) {
        if (flag) {//右子树
            parent->Right = root->Right;
        } else {//左子树
            parent->Left = root->Right;
        }
        return true;
    }
    //4.删除节点有左右子树
    if (root->Val == val) {
        //右子树上的比左子树的都要大
        BiLink p = root->Left;
        while (p->Right != NULL);//找左子树中最大的
        p->Right = root->Right;
        root->Right = NULL;
        //合并成左子树
        del(root, parent, val, flag);//转化为情况2(只有左子树)
    }
    if (val < root->Val) {
        return del(root->Left, root, val, false);
    } else {
        return del(root->Right, root, val, true);
    }
}

//创建一颗二叉搜索树
BST NewBST(int *nums, int length) {
    //1.创建一颗二叉搜索树
    BST that;
    that.root.Right = NULL;
    that.length = 0;
    for (int i = 0; i < length; i++) {
        Insert(&that, nums[i]);
    }
    that.length = length;
    return that;
}

// 先序遍历
void preTravel(BiLink root) {
    if (root == NULL) {
        return;
    }
    preTravel(root->Left);
    printf("%d ", root->Val);
    preTravel(root->Right);
}

void PreTravel(BST that) {
    BiLink head = &that.root;
    if (head->Right == NULL) {
        return;
    }
    preTravel(head->Right);
}

int main() {
    int array[] = {9, 8, 76, 54, 3, 11, 3, 2, 43, 5, 3};
    BST that = NewBST(array, 11);
//    Insert(&that,99);
    PreTravel(that);
    printf("\n");
    Del(&that, 8);
//    printf("%d\n",that.length);
    PreTravel(that);
}
```

