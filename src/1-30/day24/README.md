# [45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)
### 解法1:贪心回溯+剪枝

``` c
int Mincount;
int jump(int* nums, int numsSize){
    //贪心回溯
    Mincount=numsSize;
    helper(nums,numsSize,0,0);
    return Mincount;
}
void  helper(int *nums,int numsSize,int position,int count){    
    //剪枝
    if(count+1>Mincount){
        return;
    }
    if(position>numsSize-1){
        return;
    }
    if(position==numsSize-1&&count<Mincount){
        Mincount=count;
        return;
    }
    for(int i=1;i<=nums[position];i++){
        helper(nums,numsSize,position+i,count+1);
    }
}
```
80 / 92 个通过测试用例(超时)

超时分析：存在重复计算的子问题

### 解法2：动态规划

类似最长递增子序列

``` c
int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
int jump(int* nums, int numsSize){
    int dp[numsSize];
    dp[0]=0;
    int m;
    for(int i=1;i<numsSize;i++){
        m=numsSize;
        for(int j=0;j<i;j++){            
            if(nums[j]+j>=i){
                m=min(dp[j]+1,m);
            }
        }
        dp[i]=m;
    }
    return dp[numsSize-1];
}
```

91 / 92 个通过测试用例(超时)

### 解法3：贪心算法

思想：每次选择最有可能一步到达终点的下一跳

即 i+nums[i]

``` c
int jump(int* nums, int numsSize){
    if(numsSize==1){
        return 0;
    }
    int ret=0;
    int i=0;
    int next;
    while(i<numsSize){
        next=i+1;
          if(i+nums[i]>=numsSize-1){
            return ret+1;
        }
        for(int j=1;j<=nums[i];j++){         
            //贪心选择
            if(nums[next]+next<=nums[i+j]+i+j){
                next=i+j;
            }
        }
        i=next;
        printf("%d",next);
        ret++;
    }
    return 0;
}
```

### 解法3(改进)：

``` c
int jump(int* nums, int numsSize){
   int ret=0;
   int i=0;
   while(i<numsSize){
       //0.已经在终点
       if(i==numsSize-1){
           return ret;
       }
       //1.一跳内能够到达终点
       if(i+nums[i]>=numsSize-1){
           return ret+1;
       }
       //2.选择最远
       int next=i;
       for(int j=1;j<=nums[i];j++){
           if(nums[next]+next<=nums[i+j]+i+j){
               next=i+j;
           }
       }
       //3.状态转移
       i=next;
       ret++;
   }
   // 该处返回值无效
   return -1;
}
```

