## [152. 乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/)

### 动态规划算法:

**1.状态定义**

dp_min[i]代表以nums[i]元素结尾的乘积最小乘积

dp_max[i]代表以nums[i]结尾的最大乘积最大乘积

**2.分类讨论**

对于两个整数a和b，已知a<b 乘上第三个数c之后共得到3个整数:ac,bc,c。问它们之间的大小关系？

**情况1:c>0**

2.1.1 0<a<b  --->  c<=ac<bc (因为a>=1 所以ac>=c) 

2.1.2 a<0<b  --->  ac<0<c<=bc(因为b>=1 所以bc>=c) 

2.1.3 a<b<0 ---->  ac<bc<0<c

由上述式子可以得：

当c>0时，最小值可能是c或者ac

最大值为bc或者c

在本题中 a为dp_min[i]  b 为dp_max[i]  c为nums[i] 

综上可以得出状态转移方程:

dp_min[i+1]=min(dp_min[i]*nums[i+1],c)

dp_max[i+1]=max(dp_max[i]nums[i+1],c)

**情况2：c<0**

2.2.1 0<a<b  --->  bc<ac<=c (因为a>=1 所以ac<=c) 

2.2.2 a<0<b  --->  bc<=c<0<ac(因为b>=1 所以bc<=c) 

2.2.3 a<b<0 ----> c<0<bc<ac

由上述式子可以得：

当c<0时，最小值可能是c或者bc

最大值为ac或者c

综上可以得出状态转移方程:

dp_min[i+1]=min(dp_max[i]*nums[i+1],c)

dp_max[i+1]=max(dp_min[i]nums[i+1],c)

**情况3：c=0**

dp_min[i+1]=0

dp_max[i+1]=0

``` c

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

int maxProduct(int* nums, int numsSize){
    int dp_min[numsSize];
    int dp_max[numsSize];
    dp_min[0]=nums[0];
    dp_max[0]=nums[0];
    int ret=nums[0];
    for(int i=1;i<numsSize;i++){
       if(nums[i]>0){
           dp_min[i]=min(dp_min[i-1]*nums[i],nums[i]);
           dp_max[i]=max(dp_max[i-1]*nums[i],nums[i]);
       } else if(nums[i]<0){
            dp_min[i]=min(dp_max[i-1]*nums[i],nums[i]);
            dp_max[i]=max(dp_min[i-1]*nums[i],nums[i]);
       }else{
           dp_max[i]=0;
           dp_min[i]=0;
       }
       if(dp_max[i]>ret){
           ret=dp_max[i];
       }
    }
    // for(int i=0;i<numsSize;i++){
    //     printf("%d ",dp_max[i]);
    // }
    // printf("\n");
    //     for(int i=0;i<numsSize;i++){
    //     printf("%d ",dp_min[i]);
    // }
    // printf("\n");
    return ret;
}
```

