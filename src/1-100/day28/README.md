## 每日一道编程题（10）：二叉排序树

（**2017哈工大854**）

给定一颗n个结点的二叉排序树（即BST），每个结点均存放一个整数，其结点格式为[lchild][data][rchild].

令half=（BST中的最大值+BST中的最小值）/2。

设计一个算法BinTree findNearMid（BinTree *root）.

完成（1）找出BST中最大和最小值以计算half的值；

​    （2） 返回大于half且与half相差最小的结点。

``` c
void helper(BiLink root, int *ret, float target) {
    //先序遍历
    if (root == NULL) {
        return;
    }
    if (target < root->Val) {
        helper(root->Left, ret, target);
        if (*ret == -1) {
            *ret = root->Val;
        }
    } else if (target > root->Val) {
        helper(root->Right, ret, target);
    }
}

// 题解
void solution(BiLink root) {
    //1.找最大值
    BiLink p = root;
    while (p->Right != NULL) {
        p = p->Right;
    }
    int max = p->Val;

    //2.找最小值
    p = root;
    while (p->Left != NULL) {
        p = p->Left;
    }
    int min = p->Val;
    double half = (min + max) / 2.0;
    printf("\nmin=%d max=%d,half=%.1f\n", min, max, half);
    //3.找最接近的数
    int ret = -1;
    helper(root, &ret, half);
    printf("ret=%d\n", ret);
}
```

