## 今日打卡

树的路径：

二叉树采用二叉链表进行存储（如下所示），每个结点包含数据域Data，左孩子指针域left和右孩子指针域right。

p所指的结点为任一给定结点，编写算法，求从根节点到p所指结点之间的路径，叙述算法思想并给出算法实现，分析时间复杂度。

``` c
//二叉树结构
typedef struct node {
    int val;
    struct node *left, *right;
} BiNode, *BiLink;

const int SIZE = 50;

BiLink NewNode(int val) {
    if (val == -1) {
        return NULL;
    }
    BiLink ret = (BiLink) malloc(sizeof(BiNode));
    ret->val = val;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

BiLink POINTER;

//建立二叉树 层次遍历 输入完全二叉树 -1代表没有该节点
BiLink create(int *array, int length, int index) {
    //1.特判
    if (length <= 0) {
        return NULL;//无法创建
    }
    BiLink *nodes = (BiLink *) malloc(sizeof(BiNode) * length);
    for (int i = 0; i < length; i++) {
        nodes[i] = NewNode(array[i]);
    }
    //测试嵌入
    POINTER = nodes[index];
    for (int i = 0; i <= (length - 2) / 2; i++) {
        if (nodes[i] == NULL) {
            continue;
        }
        nodes[i]->left = nodes[i * 2 + 1];
        nodes[i]->right = nodes[i * 2 + 2];
    }
    return nodes[0];
}

void travel(BiLink head) {
    if (head == NULL) {
        return;
    }
    travel(head->left);
    printf("%d ", head->val);
    travel(head->right);
}

bool solution(BiLink root, BiLink p) {
    if (root == NULL) {
        return false;
    }
    if (root == p) {
        printf("%d", root->val);
        return true;
    }
    if (solution(root->left, p) || solution(root->right, p)) {
        printf("<-%d", root->val);
        return true;
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    //第三个参数规定POINTER指向的位置
    BiLink root = create(array, 5, 4);
    solution(root, POINTER);
}

```







# 力扣周赛188

#### [5404. 用栈操作构建数组](https://leetcode-cn.com/problems/build-an-array-with-stack-operations/)

``` c
func buildArray(target []int, n int) []string {
	ret := make([]string, 0)
	i, j := 0, 1
	for i < len(target) && j <=n {
		if target[i] == j {
			ret = append(ret, "Push")
			i++
			j++
		} else {
			ret = append(ret, "Push", "Pop")
			j++
		}
	}
	return ret
}
```

#### [5405. 形成两个异或相等数组的三元组数目](https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)

``` c
func countTriplets(arr []int) int {
	ret := 0
	var temp int
	for i := 0; i < len(arr); i++ {
		temp = arr[i]
		for j := i + 1; j < len(arr); j++ {
			temp ^= arr[j]
			if temp == 0 {
				ret+=j-i
			}
		}
	}
	return  ret
}
```



#### [5406. 收集树上所有苹果的最少时间](https://leetcode-cn.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)

``` c
func minTime(n int, edges [][]int, hasApple []bool) int {
	//1.next数组 标记当前节点的父亲是哪个
	flag := make([]bool, n)
	next := make([]int, n)
	for i := 0; i < len(edges); i++ {
		next[edges[i][1]] = edges[i][0]
		flag[edges[i][0]] = true
	}
	//2.找到叶子节点
	queue := make([]int, 0)
	for i := 0; i < len(flag); i++ {
		if !flag[i] {
			queue = append(queue, i)
		}
	}
	// 从叶子向上染色
	for i := 0; i < len(queue); i++ {
		for j := queue[i]; j != 0; j = next[j] {
			if hasApple[j] {
				hasApple[next[j]] = true
			}
		}
	}
	ret := 0
	for i := 1; i < len(hasApple); i++ {
		if hasApple[i] {
			ret++
		}
	}
	fmt.Println(ret)
	return ret * 2
}
```

