## 今日打卡

树的路径：

二叉树采用二叉链表进行存储（如下所示），每个结点包含数据域Data，左孩子指针域left和右孩子指针域right。

p所指的结点为任一给定结点，编写算法，求从根节点到p所指结点之间的路径，叙述算法思想并给出算法实现，分析时间复杂度。

``` c
typedef struct BitNode{  
   int data; 
   struct BitNode *left, *right;
} *BiTree ;
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

