#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned int x = 20u;
    int y = 30;
    bool flag = x - y < 0;
    // 期望输出结果是 `true`
    printf("%s\n", flag ? "true":"false"); 
}