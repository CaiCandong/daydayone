#include <stdio.h>

int longest(int *array, int length, int target) {
    //双指针解法
    int i = 0, j = 0;
    int sum;
    int ret = 0;
    while (i < length) {
        //i.每次指向不同的数字
        j = i;
        sum = 0;
        while (array[j] == array[i]) {
            sum += array[j];
            j++;
        }
        if (sum == target && j - i > ret) {
            ret = j - i;
        }
        i = j;
    }
    return ret;
}

int main() {
//    int A[]={1,1,2,1,1,1,2,1};
//    int length=8;
//    int s=3;
    //答案:3
//    int A[]={1,3,4,5,1,3,2,1};
//    int length=8;
//    int s=6;
    // 答案:0
    int A[]={1};
    int length=1;
    int s=1;
    //答案：1
    int ret=longest(A,length,s);
    printf("%d",ret);
}