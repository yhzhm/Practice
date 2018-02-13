/*
13:反向输出一个三位数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
将一个三位数反向输出。

输入
一个三位数n。
输出
反向输出n。
样例输入
100
样例输出
001
*/


#include <stdio.h>
int main ()
{
	int a,b1,b2,b3;
	scanf("%d",&a);
	b3=a%10;a/=10;
	b2=a%10;a/=10;
	b1=a;
	printf("%d%d%d",b3,b2,b1);
	return 0;
}
