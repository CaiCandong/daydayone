# 力扣双周赛(3/4)

## 1.连续字符

给你一个字符串 `s` ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串的能量。

**示例 1：**

```
输入：s = "leetcode"
输出：2
解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
```

**示例 2：**

```
输入：s = "abbcccddddeeeeedcba"
输出：5
解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
```

**示例 3：**

```
输入：s = "triplepillooooow"
输出：5
```

**示例 4：**

```
输入：s = "hooraaaaaaaaaaay"
输出：11
```

**示例 5：**

```
输入：s = "tourist"
输出：1
```



**提示：**

- `1 <= s.length <= 500`
- `s` 只包含小写英文字母。

``` go
func maxPower(s string) int {
    if len(s)==0{
        return 0
    }
    ret:=1
    for i,j:=0,0;j<len(s)-1;i=j{
        for j=i;j<len(s)&&s[j]==s[i];j++{   
        }
        if j-i>ret{
            ret=j-i
        }
    }
    return ret
}
```

## 2.最简分数

给你一个整数 `n` ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于 `n` 的 **最简** 分数 。分数可以以 **任意** 顺序返回。

**示例 1：**

```
输入：n = 2
输出：["1/2"]
解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
```

**示例 2：**

```
输入：n = 3
输出：["1/2","1/3","2/3"]
```

**示例 3：**

```
输入：n = 4
输出：["1/2","1/3","1/4","2/3","3/4"]
解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
```

**示例 4：**

```
输入：n = 1
输出：[]
```

**提示：**

- `1 <= n <= 100`

``` go
func simplifiedFractions(n int) []string {
	ret := make([]string, 0)
	if n < 2 {
		return ret
	}
	dp := make([][]bool, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]bool, n+1)
	}
	for i := 2; i <= n; i++ {
		for j := 1; j < i; j++ {
			if !dp[i][j] {
				ret = append(ret, fmt.Sprintf("%d/%d", j, i))
				for k := 2; i*k <=n && j*k <=n; k++ {
					dp[i*k][j*k] = true
				}
			}

		}
	}
	return ret
}
```

## 3.统计二叉树中好节点的数目

给你一棵根为 `root` 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值

``` go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ret int
func goodNodes(root *TreeNode) int {
    ret=1
    helper(root.Left,root.Val)
    helper(root.Right,root.Val)
    return ret
}
func helper(root *TreeNode,max int){
    if root==nil{
        return
    }
    if root.Val>=max{
        ret++
        max=root.Val
    }
    helper(root.Left,max)
    helper(root.Right,max)    
}
```

## 4.数位成本和为目标值的最大数字

给你一个整数数组 `cost` 和一个整数 `target` 。请你返回满足如下规则可以得到的 **最大** 整数：

- 给当前结果添加一个数位（`i + 1`）的成本为 `cost[i]` （`cost` 数组下标从 0 开始）。
- 总成本必须恰好等于 `target` 。
- 添加的数位中没有数字 0 。

由于答案可能会很大，请你以字符串形式返回。

如果按照上述要求无法得到任何整数，请你返回 "0" 。

``` java
class Solution {
  public String largestNumber(int[] cost, int target) {

    String[] dp = new String[target + 1];
    dp[target] = "";
    for (int i = target - 1; i >= 0; i--) {
      for (int j = 0; j < 9; j++) {
        if (i + cost[j] > target) continue;

        if (dp[i+cost[j]] == null)  continue;

        String newStr = (dp[i + cost[j]] + (j + 1)).intern();
        if (dp[i] == null)
          dp[i]= newStr;
        else if (strLarger(newStr, dp[i]))
          dp[i] = newStr;
      }
    }

    return dp[0] == null ? "0" : dp[0];
  }

  private boolean strLarger(String a, String b) {
    if (a.length() > b.length()) return true;
    else if (a.length() < b.length()) return false;
    return a.compareTo(b) > 0;
  }
}
```

# 力扣周赛(3/4)]

## [1450. 在既定时间做作业的学生人数](https://leetcode-cn.com/problems/number-of-students-doing-homework-at-a-given-time/)

``` go 
func busyStudent(startTime []int, endTime []int, queryTime int) int {
    ret:=0
    for i:=0;i<len(startTime);i++{
        if queryTime>=startTime[i]&&queryTime<=endTime[i]{
            ret++
        }
    }
    return ret
}
```

## [1451. 重新排列句子中的单词](https://leetcode-cn.com/problems/rearrange-words-in-a-sentence/)

``` go
func Capitalize(str string) string {
	var upperStr string
	vv := []rune(str) // 后文有介绍
	for i := 0; i < len(vv); i++ {
		if i == 0 {
			if vv[i] >= 97 && vv[i] <= 122 { // 后文有介绍
				vv[i] -= 32 // string的码表相差32位
				upperStr += string(vv[i])
			} else {
				fmt.Println("Not begins with lowercase letter,")
				return str
			}
		} else {
			upperStr += string(vv[i])
		}
	}
	return upperStr
}
func arrangeWords(text string) string {
	text = strings.ToLower(text)
	array := strings.Split(text, " ")
	for i := 0; i < len(array); i++ {
		for j := 0; j < len(array)-i-1; j++ {
			if len(array[j+1]) < len(array[j]) {
				array[j], array[j+1] = array[j+1], array[j]
			}
		}
	}
	array[0] = Capitalize(array[0])
	ret := strings.Join(array, " ")
	return ret
}
```

## [1452. 收藏清单](https://leetcode-cn.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/)

``` go
func isSub(strs1, strs2 []string) bool {
	if len(strs1) < len(strs2) {
		return false
	}
	m := make(map[string]bool)
	for i := 0; i < len(strs1); i++ {
		m[strs1[i]] = true
	}
	for i := 0; i < len(strs2); i++ {
		if !m[strs2[i]] {
			return false
		}
	}
	return true
}
func peopleIndexes(favoriteCompanies [][]string) []int {
	flag := make([]bool, len(favoriteCompanies))
	// 指向超集
	//sub := make([]int, len(favoriteCompanies))
	//for i := 0; i < len(sub); i++ {
	//	sub[i] = -1
	//}
	for i := 0; i < len(favoriteCompanies); i++ {
		for j := 0; j < len(favoriteCompanies); j++ {
			if i == j || flag[j] {
				continue
			}
			if isSub(favoriteCompanies[i], favoriteCompanies[j]) {
				flag[j] = true
			}
		}
	}
	ret := make([]int, 0)
	for i := 0; i < len(flag); i++ {
		if !flag[i] {
			ret = append(ret, i)
		}
	}
	return ret
}
```

# 每日一题

## [210. 课程表 II](https://leetcode-cn.com/problems/course-schedule-ii/)

``` c
func findOrder(numCourses int, prerequisites [][]int) []int {
    //入度表
    pre:=make([]int,numCourses)
    for i:=0;i<len(prerequisites);i++{
        pre[prerequisites[i][0]]++
    }
    ret:=make([]int,0)
    flag:=false
    for numCourses!=0{
        flag=true
        for i:=0;i<len(pre);i++{
            if pre[i]==0{
                flag=false
                pre[i]--
                numCourses--
                 ret=append(ret,i)
                 for j:=0;j<len(prerequisites);j++{
                    if prerequisites[j][1]==i{
                        pre[prerequisites[j][0]]--
                    }
                 }
            }
        }
        if flag{
            return nil
        }
    }
    return ret
}
```

