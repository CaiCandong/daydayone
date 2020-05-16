#### [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

``` c\
int subarraySum(int* nums, int numsSize, int k){
    int sum;
    int ret=0;
    for(int i=0;i<numsSize;i++){
        sum=0;
        for(int j=i;j<numsSize;j++){
            sum+=nums[j];
            if(sum==k){
                ret++;
            }
        }
    }
    return ret;
}
```

