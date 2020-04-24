#include<stdio.h>
#include<string.h>
/**
 * 输入单词字符串str,字符串长度Length 
 * 单词的个数
 */ 
int countWord(char *str,int length){
// 1.删除开头的空格
    int i=0,j=length-1;
    for(;i<length;i++){
       if(str[i]!=' '){
           break;
       } 
    }
// 2.删除结尾的空格 
    for(;j>0;j--){
        if(str[i]!=' '){
            break;
        }
    }
    int result=0;
//3.数有效空格的数量
    while (i<j){
        if(str[i]!=' '){
            i++;
            continue;
        }else{
            result++;//记录单词个数
            while(i<j){//跳跃无效空格
                if(str[i]==' '){
                    i++;
                }else{
                	break;
				} 
            }
        }
    }
   return result+1; 
}
int main(){
    // char str[]="To be or not to be        This is a question";
    char str[100];
    gets(str);
    int length=strlen(str);
    int res=countWord(str,length);
    printf("%d",res);
}
