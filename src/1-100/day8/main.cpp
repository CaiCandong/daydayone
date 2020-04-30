#include <stdio.h>
#include <malloc.h>
float solution(int n)
{
    if (n < 3)
    {
        return 0.0;
    }
    // 规律:每增加两条边,面积增加2
    if (n % 2 == 1)
    {   //奇数,在3的基础上增加
        // 奇数起点3:
        return (n - 3) + 0.5;
    }
    else
    {
        //偶数起点为4
        return (n - 4) + 2.0;
    }
}
int main()
{
    printf("3-%.1f\n", solution(3));
    printf("4-%.1f\n", solution(4));
    printf("5-%.1f\n", solution(5));
    printf("6-%.1f\n", solution(6));
}
