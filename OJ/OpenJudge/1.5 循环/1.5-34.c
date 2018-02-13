/*
34:求阶乘的和
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定正整数n，求不大于n的正整数的阶乘的和（即求1!+2!+3!+...+n!）

输入
输入有一行，包含一个正整数n（1 < n < 12）。
输出
输出有一行：阶乘的和。
样例输入
5
样例输出
153
*/

#include <stdio.h>
int main()
{
	int n,i,j;
	long long sum=0,s;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		for (s=1,j=1;j<=i;j++){
			s*=j;
		}
		sum+=s;
	}
	printf("%lld",sum);
	return 0;
}
