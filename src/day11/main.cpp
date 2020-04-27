#include<stdio.h>
#include<string.h>
#include<malloc.h>

//0:正确
//1:长度不对
//2:校验失败
int isValidity(int id[],int length){
    if(length!=18){
        return 1;
    }
    int flag=0;
    //生成校验位
    const int map[11]={1 ,0 ,'x'-'0' ,9 ,8 ,7 ,6 ,5 ,4 ,3 ,2};
    const int W[17]={7, 9, 10, 5 ,8 ,4 ,2 ,1 ,6 ,3 ,7 ,9 ,10, 5 ,8 ,4 ,2};
    for(int i=0;i<17;i++){
        flag+=W[i]*id[i];
        flag%=11;
    }
    return id[17]!=map[flag];
}
int *str2int(char *str){
    int length=strlen(str);
    int *res=(int*)malloc(sizeof(int)*length);
    for(int i=0;i<length;i++){
        res[i]=str[i]-'0';
    }
    return res;
}
int main(){
   char str[18]; 
   scanf("%s",str);
   printf("%d",strlen(str));
   int flag=isValidity(str2int(str),strlen(str));
    printf("%d",flag);
    if(flag==0){
        printf("%s 校验正确",str);
    }
}