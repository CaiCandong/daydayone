#include<stdio.h>
#include <malloc.h>
/**
 * 动态规划算法:
 * 以[-2,1,-3,4,-1,2,1,-5,4]为例子
 * 状态定义:dp[i] 
 * 
 * 
 */
int maxSubArray(int array[],int length){
    int sum=0;
    int ret=array[0];
    for(int i=0;i<length;i++){
        if(sum<0){
            sum=array[i];
        }else{
            sum+=array[i];
        }
        if(sum>ret){
            ret=sum;
        }
    }
    return ret;
}
int main(){
    int array[]={6,-3,-2,7,-15,1,2,2};
    int ret=maxSubArray(array,8);
    printf("%d",ret);
}