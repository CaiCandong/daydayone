#include <stdio.h>
bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i < n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
bool isvalid(int x, int y[3])
{
    if (x > 50 || x < 0)
    {
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        if (y[i] > 50 || y[i] < 0)
        {
            return false;
        }
    }
    return true;
}
//-1输入不合法
//0成功
//1,2,3失败关数
int solution(int x, int y[3])
{
    if (!isvalid(x, y))
    {
        return -1;
    }
    for (int i = 0; i < 3; i++)
    {
        if (!isPrime((x - y[i]) * (x - y[i]) + (x - y[i]) + 41))
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    int x = 0;
    int y[3] = {20, 30, 20};
    int res = solution(x, y);
    switch (res)
    {
    case -1:
        printf("输入不合法");
        break;
    case 0:
        printf("WIN");
        break;
    default:
        printf("%d关失败", res);
    }
}