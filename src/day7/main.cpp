#include <stdio.h>
#include <malloc.h>
// 简单双指针,力扣题解
bool isSubsequence(char *s, char *t)
{
    int i = 0, j = 0;
    while (s[i] != '\0' && t[j] != '\0')
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return s[i] == '\0';
}
//中南题解
bool match(char t[])
{
    return isSubsequence("EASY", t);
}
int main()
{
    printf("%d\n",match("eAsy"));
    printf("%d",match("SEoAtSNY"));
}
