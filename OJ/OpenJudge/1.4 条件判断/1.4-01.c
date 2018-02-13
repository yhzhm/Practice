/*
01:判断数正负
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个整数N，判断其正负。



输入
一个整数N(-109 <= N <= 109)
输出
如果N > 0, 输出positive;
如果N = 0, 输出zero;
如果N < 0, 输出negative
样例输入
1
样例输出
positive
*/

#include <stdio.h>
int main()
{
	long long a;
	scanf("%lld", &a);
	if (a>0) printf("positive");
	else if (a==0) printf("zero");
	else printf("negative");		
	return 0;
}
