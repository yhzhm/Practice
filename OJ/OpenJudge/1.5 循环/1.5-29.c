/*
29:数字反转
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例2）。

输入
输入共 1 行，一个整数N。

-1,000,000,000 ≤ N≤ 1,000,000,000。
输出
输出共 1 行，一个整数，表示反转后的新数。
样例输入
样例 #1：
123

样例 #2：
-380
样例输出
样例 #1：
321

样例 #2：
-83
*/



#include <stdio.h>
int main()
{
	long long n;
	scanf("%lld",&n);
	if (n<0){
		printf("-");
		n=-n;
	}
	while(!(n%10)){
		n/=10;
	}
	while(n!=0){
		printf("%d",n%10);
		n/=10;
	}
	return 0;
}

#include <stdio.h>
int main()
{
	long long n,s=0;
	scanf("%lld",&n);
	if (n<0){
		printf("-");
		n=-n;
	}
	while(n!=0){
		s=s*10+n%10;
		n/=10;
	}
	printf("%lld",s);
	return 0;
}
