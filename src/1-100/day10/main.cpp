#include<stdio.h>
#include<malloc.h>
// 存在溢出问题 dp声明为longlong类型
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
   if(obstacleGrid[0][0]==1){
       return 0;
   }
   int m=obstacleGridSize;
   int n=*obstacleGridColSize; 
   // 直接使用自身作为dp数组
   int **dp=obstacleGrid;
   dp[0][0]=1;
   //横向初始化
   for(int i=1;i<n;i++){
       if (obstacleGrid[0][i]==1){
            dp[0][i]=0;
       }else{
           dp[0][i]=dp[0][i-1];
       }
   }
   //纵向初始化
	for (int i = 1; i < m; i++ ){
		if (obstacleGrid[i][0] == 1 ){
			dp[i][0] = 0;
		} else {
			dp[i][0] = dp[i-1][0];
		}
	}
	//dp迭代
	for (int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			if (obstacleGrid[i][j] == 1) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}
    return dp[m-1][n-1];
}
