int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
bool canJump(int* nums, int numsSize){
    // m为最大距离
    int m=0;
    int i=0;
    while(i<=m&&i<numsSize){
        m=max(m,nums[i]+i);
        i++;
    }
    // 最大距距离是否超过目的地
    if(m>=numsSize-1){
        return true;
    }
    return false;
}