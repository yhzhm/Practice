/*
08:打印字符
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个ASCII码，输出对应的字符。

输入
一个整数，即字符的ASCII码，保证存在对应的可见字符。
输出
一行，包含相应的字符。
样例输入
65
样例输出
A
*/

//#include <stdio.h>
//int main()
//{
//	_Bool a;
//	int b;
//	scanf("%d",&b);
//	a = b;
//	b = a;
//	printf("%d",b);
//	return 0;
//}


#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",(int)(_Bool)a);
	return 0;
}
