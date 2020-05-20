#### [1371. 每个元音包含偶数次的最长子字符串](https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)

``` c 
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int findTheLongestSubstring(char * s){
    //1<<5;// 按位存储,从00000 分别存储uoiea奇偶
    int n=strlen(s);
    int ret=0;
    int *dp=(int *)malloc(sizeof(int)*32);//记录该种状态的最短长度
    for(int i=0;i<32;i++){
        dp[i]=-1;//标记为没有记录过
    }
    dp[0]=0; //第1个为0 就是长度为0的字符串
    int ans=0;// 最开始全部为偶数个(0个)
    for(int i=0;i<n;i++){
        //更新状态
        switch (s[i]){
            case 'a':ans^=1<<0;break;
            case 'e':ans^=1<<1;break;
            case 'i':ans^=1<<2;break;
            case 'o':ans^=1<<3;break;
            case 'u':ans^=1<<4;break;
        }
        //根据状态修改返回值 与相同状态进行比较
        if(dp[ans]!=-1){
            ret=max(ret,i-dp[ans]+1);
        }else{
            dp[ans]=i+1;//+1的目的 
        }
    }
    return ret;
}
```

