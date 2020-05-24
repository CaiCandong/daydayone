#### **最小覆盖子串**

``` c
func minWindow(s string, t string) string {
	//记录有效窗口中每个字符最小数量
	target := make(map[byte]int)
	//记录窗口中每个字符的个数
	dp := make(map[byte]int)
	for i := 0; i < len(t); i++ {
		target[t[i]]++
	}
	// 记录符合条件的元素的个数
	cnt, l, r := 0, 0, 0
	flag := true
	//1.初始化窗口
	for r = 0; r < len(s) && cnt < len(target); r++ {
		if _, ok := target[s[r]]; ok {
			if flag {
				l = r
				flag = false
			}
			dp[s[r]]++
			if dp[s[r]] == target[s[r]] {
				cnt++
			}
		}
	}
	if cnt < len(target) {
		return ""
	}
	//fmt.Println(target, dp, cnt)
	//fmt.Println(l, r)
	for _, ok := target[s[l]]; !ok || (ok && dp[s[l]] > target[s[l]]); {
		if ok {
			dp[s[l]]--
		}
		l++
		_, ok = target[s[l]]
		//fmt.Println("收缩",l)
	}
	//2.窗口移动
	ret_l, ret_r := l, r
	for ; r < len(s); r++ {
		//尝试收缩
		if _, ok := target[s[r]]; ok {
			dp[s[r]]++
			fmt.Println("尝试收缩:", s[l:r+1])
			for _, ok := target[s[l]]; !ok || (ok && dp[s[l]] > target[s[l]]); {
				if ok {
					dp[s[l]]--
				}
				l++
				_, ok = target[s[l]]
				//fmt.Println("收缩",l)
			}
			fmt.Println("收缩后:", s[l:r+1])
		}
		if r-l < ret_r-ret_l {
			ret_l, ret_r = l, r+1
		}

	}
	//fmt.Println("l:", ret_l, "r:", ret_r)
	//fmt.Println(ret_l, ret_r, s[ret_l:ret_r])
	return s[ret_l:ret_r]
}
```

