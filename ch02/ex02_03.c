/** 
 * 
 * ex02_03.c - 使用 牛顿法 计算任意正浮点数的平方根
 * 
 * 参考资料
 * + https://en.wikipedia.org/wiki/Newton%27s_method
 *
 * 牛顿法基本步骤
 * 1. 选择一个接近函数 f(x) 的零点 x0
 * 2. 计算 f(x0) 和 f'(x0)
 * 3. 计算穿过点 (x0, f(x0)) 并且斜率为 f'(x0) 的直线与 x 轴交点的坐标
 *      0 = (x - x0) f'(x0) + f(x0)
 * 4. 得到的 x 坐标命名为 x1。这个 x1 就会比 x0 更接近 f(x) = 0 的解。因此，利用 x1 继续迭代
 * 
 * 迭代公式为
 * x_{n+1} = x_n - f(x_{n}) / f'(x_{n})
**/


#include <stdio.h>
#include <math.h>

/**
 * 使用牛顿法计算平方根。
 * 
 * x^2 = m  =>  f(x) = x^2 - m  => f(x) 的零点
 * 
 * x_{n+1} = x_{n} - f(x_{n}) / f'(x_{n})
 * x_{n+1} = x_{n} - (x_{n}^2 - m) / (2 * x_{n})
**/
double NewtonSqrt(const double m)
{
    const double err = 1e-8;
    if (m < 0) 
    {
        return -1.0;
    }
    double result = m;
    // 如果原值减去近似根的平方大于误差，继续循环
    while (fabs(m - result * result) >= err)
    {
        result = result - (result * result - m) / (2.0 * result);
    }
    return result;
}

int main(void)
{
    printf("%lf", NewtonSqrt(2));
}

