#### [680. 验证回文字符串 Ⅱ](https://leetcode-cn.com/problems/valid-palindrome-ii/)

``` c
bool helper(char *s ,int i,int j){
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}
bool validPalindrome(char * s){
    int j=strlen(s)-1;
    int i=0;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            return helper(s,i,j-1)||helper(s,i+1,j);
        }
    }
    return true;
}
```

