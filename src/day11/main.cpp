#include <stdio.h>
#include <string.h>

//0:正确
//1:长度不对
//2:校验失败
int isValidity(char id[]){
    if (strlen(id) != 18){
        return 1;
    }
    int flag = 0;
    //生成校验位
    char map[] = "10x98765432";
    const int W[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    for (int i = 0; i < 17; i++){
        flag += W[i] * (id[i] - '0');
    }
    flag %= 11;
    if (id[17] == map[flag]){
        return 0;
    }
    return 2;
}

int main(){
    char str[30];
    scanf("%s", str);
    if (isValidity(str) == 0){
        printf("%s 校验正确", str);
    }    
    return 0;
}