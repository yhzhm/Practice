/*
02:浮点型数据类型存储空间大小
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
分别定义float，double类型的变量各一个，并依次输出它们的存储空间大小（单位：字节）。



输入
无。
输出
一行，两个整数，分别是两个变量的存储空间大小，用一个空格隔开。
样例输入
（无）
样例输出
（不提供）
*/


#include <stdio.h>
int main ()
{
	float a;
	double b;
	printf("%d %d",sizeof(a),sizeof(b));
	return 0;
}
