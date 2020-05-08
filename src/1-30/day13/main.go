package main

import "fmt"

//学生信息
type Student struct {
	Name  string
	score [4]int
}

func isFail(stu Student) bool {
	for i := 0; i < 3; i++ {
		if stu.score[i] < 60 {
			return true
		}
	}
	return false
}
func solution(stus []Student) []Student {
	//直接排序
	res := make([]Student, 0)
	// 插入

	// 名单排序
	for i := 0; i < len(stus); i++ {
		for j := 0; j < len(stus)-i-1; j++ {
			if stus[j].score[3] > stus[j+1].score[3] {
				stus[j], stus[j+1] = stus[j+1], stus[j]
			}
		}
	}
	flag := make([]bool, len(stus))
	for i := 0; i < len(stus); i++ {
		// 选择挂科人员
		if isFail(stus[i]) {
			//插入挂科名单中
			res = append(res, stus[i])
			flag[i] = true
		}
	}
	for i := 0; i < len(stus); i++ {
		if !flag[i] {
			res = append(res, stus[i])
		}
	}
	return res
}
func main() {
	stus := []Student{
		{"zhaoyi", [4]int{70, 80, 90, 240}},
		{"qianer", [4]int{65, 32, 77, 174}},
		{"sunsan", [4]int{100, 55, 68, 223}},
		{"lisi", [4]int{86, 77, 90, 253}},
		{"wangwu", [4]int{100, 59, 66, 225}},
	}
	res := solution(stus)
	fmt.Println(res)
}
