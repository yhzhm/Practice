/*
17:菲波那契数列
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
菲波那契数列是指这样的数列: 数列的第一个和
第二个数都为1，接下来每个数都等于前面2个数
之和。
给出一个正整数k，要求菲波那契数列中第k个数
是多少。

输入
输入一行，包含一个正整数k。（1 <= k <= 46）
输出
输出一行，包含一个正整数，表示菲波那契数列中
第k个数的大小
样例输入
19
样例输出
4181
*/


#include <stdio.h>
int main ()
{
	int k,a,b,i,t;
	scanf("%d",&k);
	a=b=1;
	for(i=3;i<=k;i++){
		t=a+b;a=b;b=t;
		printf("%d %d\n",a,b);
	}
	printf("%d",b);
	return 0;
}





