/*
20:计算2的幂
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定非负整数n，求2n。

输入
一个整数n。0 <= n < 31。
输出
一个整数，即2的n次方。
样例输入
3
样例输出
8
*/

#include <stdio.h>
#include <math.h>
int main()
{
	long long n, a;
	scanf("%lld", &n);
	a = pow(2,n);
	printf("%lld", a);
	return 0;
}
