#include<stdio.h>
#include<string.h>
#include<malloc.h>
//宏函数
#define isDigit(ch) ch>='0'&&ch<='9' 
int frogPoints(const char*ops){
    //获取长度
    int length=strlen(ops);
    //计分数组
    int *dp=(int*)malloc(sizeof(int)*length);
    int top=0;
    for(int i=0;i<length;i++){
        if(isDigit(ops[i])){
            dp[top]=ops[i]-'0';
            top++;
        }
        if(ops[i]=='+'){
            dp[top]=dp[top-1]+dp[top-2];
            top++;
        }
        if(ops[i]=='C'){
            top--;
        }
        if(ops[i]=='D'){
            dp[top]=2*dp[top-1];
            top++;
        }
    }
    //统计分数
    int ret=0;
    for(int j=0;j<top;j++){
        ret+=dp[j];
    }
    //释放内存
    free(dp);
    return ret;
}
int main(){
    char *str="52CD+";
    int ret=frogPoints(str);    
    printf("%d",ret);
    //30
}
