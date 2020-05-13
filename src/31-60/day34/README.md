# [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

## 解法1:使用队列广度优先遍历

``` go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    //使用队列
    if root==nil{
        return nil
    }
    //初始化
    res:=make([][]int,0)
    queue:=[]*TreeNode{}
    level:=[]int{}
    queue=append(queue,root)
    level=append(level,0)
    for len(queue)!=0{
        //出队列
        cur_node:=queue[0]
        cur_level:=level[0]
        queue=queue[1:]
        level=level[1:]

        if len(res)<cur_level+1{
            res=append(res,[]int{})
        }

        res[cur_level]=append(res[cur_level],cur_node.Val)

        if cur_node.Left!=nil{
            queue=append(queue,cur_node.Left)
            level=append(level,cur_level+1)
        }
       if cur_node.Right!=nil{
            queue=append(queue,cur_node.Right)
            level=append(level,cur_level+1)
        }
    }
    return res
}
```

## 解法2：深度优先遍历

``` go
var result [][]int

func levelOrder(root *TreeNode) [][]int {
	result = make([][]int, 0)
	helper(root, 0)
	return result
}
func helper(root *TreeNode, level int) {
	if root==nil{
		return
	}
	if len(result)-1 < level {
		result = append(result, make([]int, 0))
	}
	result[level] = append(result[level], root.Val)
	helper(root.Left,level+1)
	helper(root.Right,level+1)
}
```

