/*
36:计算多项式的值
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
假定多项式的形式为xn+xn-1+…+x2+x+1，请计算给定单精度浮点数x和正整数n值的情况下这个多项式的值。

输入
输入仅一行，包括x和n，用单个空格隔开。x在float范围内，n <= 1000000。
输出
输出一个实数，即多项式的值，精确到小数点后两位。保证最终结果在float范围内。
样例输入
2.0 4
样例输出
31.00
*/

#include <stdio.h>
#include <math.h>
int main()
{
	float x,sum=0.0;
	long long n;
	scanf("%f %d",&x,&n);
	for (;n>=0;n--){
		sum+=pow(x,n);
	}
	printf("%.2f",sum);
	return 0;
}
