/*
09:字符菱形
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符，用它构造一个对角线长5个字符，倾斜放置的菱形。

输入
输入只有一行， 包含一个字符。
输出
该字符构成的菱形。
样例输入
*
样例输出
  *
 ***
*****
 ***
  *
*/


#include <stdio.h>
int main()
{
	char	a;
	scanf("%c",&a);
	printf("  %c\n",a);
	printf(" %c%c%c\n",a,a,a);
	printf("%c%c%c%c%c\n",a,a,a,a,a);
	printf(" %c%c%c\n",a,a,a);
	printf("  %c\n",a);
	return 0;
}
