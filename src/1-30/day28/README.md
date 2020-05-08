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

# 解法2

```c
//非递归解法
void solution2(BiLink root) {
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
    double val = (min + max) / 2.0;
    printf("\nmin=%d max=%d,half=%.1f\n", min, max, val);
    //3.找最接近的数
    p = root;
    BiLink ret = NULL;
    // 预设条件:val的值介于min和max之间
    // 总共三种情况
    // 1.当前值大于目标值:
    //  两种可能:a.当前值就是上确界 b.上确界在左子树内
    //  操作:把当前值记录下来,进入左子树继续寻找可能的解
    // 2.当前值小于目标值:
    //  一种可能:上确界在右子树内
    //  操作:进入右子树继续寻找可能的解
    // 3.当前值等于目标值:
    //  两种可能：a.右子树不为空 b.右子树为空
    //  操作：a.上确界为右子树中的最小值
    //       b.进入右子树，结束循环 取出记录的值

//    val = 8;
    while (p != NULL) {
        if (val < p->Val) {//val在p的左子树上,当前值大于val,记录一下
            ret = p;
            p = p->Left;
        } else if (val > p->Val) {//val在p的右子树上
            p = p->Right;
        } else if (p->Right != NULL) {//为右子树的最小值
            ret = p->Right;
            while (ret->Left != NULL) {
                ret = ret->Left;
            }
            break;
        }else{
            // 把p置为NULL
            p=p->Right;
        }

    }
    if (ret != NULL) {
        printf("%d", ret->Val);
    }else{
        printf("not found!");
    };
}
```