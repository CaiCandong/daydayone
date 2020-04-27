package main

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	if obstacleGrid[0][0] == 1 {
		return 0
	}
	m, n := len(obstacleGrid), len(obstacleGrid[0])
	//dp数组
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
	}
	//初始化
	dp[0][0] = 1
	//横向初始化
	for i := 1; i < n; i++ {
		if obstacleGrid[0][i] == 1 {
			dp[0][i] = 0
		} else {
			dp[0][i] = dp[0][i-1]
		}
	}
	//纵向初始化
	for i := 1; i < m; i++ {
		if obstacleGrid[i][0] == 1 {
			dp[i][0] = 0
		} else {
			dp[i][0] = dp[i-1][0]
		}
	}
	//dp迭代
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if obstacleGrid[i][j] == 1 {
				dp[i][j] = 0
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1]
			}
		}
	}
	return dp[m-1][n-1]
}
func main() {
	data := make([][]int, 3)
	data[0] = []int{0, 0, 0}
	data[1] = []int{0, 1, 0}
	data[2] = []int{0, 0, 0}
	uniquePathsWithObstacles(data)
}
