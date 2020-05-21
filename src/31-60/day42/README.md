#### [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)

``` c
char * longestPalindrome(char * s){
	char *str=(char *)malloc(sizeof(char)*10000);
    int n=strlen(s);
    int start=0,len=1;
    int l,r;
    int temp;//遇到重复字符 mid向后滑动
    for(int mid=0;mid<n;mid++){
        for(l=mid;l>=0&&s[l]==s[mid];l--);
        for(r=mid;r<n&&s[r]==s[mid];r++);
        temp=r-1;//temp指向最后一个重复元素
        for(;l>=0&&r<n&&s[l]==s[r];r++,l--);
        if(len<r-l-1){
            len=r-l-1;
            start=l+1;
        }
        mid=temp;
    }
    for(int i=0;i<len;i++){
        str[i]=s[i+start];
    }
    str[len]='\0';
    return str;
}
```

