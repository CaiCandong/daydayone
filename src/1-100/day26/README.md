# [41. 缺失的第一个正数 ](https://leetcode-cn.com/problems/first-missing-positive/)

## 原始代码 逻辑不够清晰
``` c
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int firstMissingPositive(int* nums, int numsSize){
	//思想:数组的每个位置是一个桶,桶里只能放编号一致的球
    //1.各元素归位
    for(int i=0;i<numsSize;i++){
        //1.非正数和大于numsSize的数没地方放,有序的不用换
        while(nums[i]>0&&nums[i]<=numsSize&&nums[i]-1!=i){
            // printf("i=%d ,%d\n",i,nums[i]);
            if(nums[i]==nums[nums[i]-1]){
                break;
            }        
            swap(&nums[i],&nums[nums[i]-1]);
        }
    }
    // for(int i=0;i<numsSize;i++){
    //     printf("%d ",nums[i]);
    // }
    int i;
    for(i=0;i<numsSize&&nums[i]-1==i;i++);
    if(i<numsSize){
        return i+1;
    }else{
        return numsSize+1;
    }
}
```

检查是否要进行交换的第三个逻辑`nums[i]-1!=i`考虑不够完全   
更加理想的写法是:`nums[i] != nums[nums[i]-1]`
``` c
int firstMissingPositive(int* nums, int numsSize){
    for(int i=0;i<numsSize;i++){
        while(nums[i]>0&&nums[i]<=numsSize&&nums[i]!=nums[nums[i]-1]){      
            int temp=nums[i];
            nums[i]=nums[temp-1];//为什么使用temp,而不是nums[i];
            nums[temp-1]=temp;
        }
    }
    int i;
    for(i=0;i<numsSize&&nums[i]-1==i;i++);
    if(i<numsSize){
        return i+1;
    }else{
        return numsSize+1;
    }
}
``` 