/*
02:找第一个只出现一次的字符
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出no。

输入
一个字符串，长度小于100000。
输出
输出第一个仅出现一次的字符，若没有则输出no。
样例输入
abcabd
样例输出
c
*/

#include <stdio.h>
#include <string.h>
char a[100000 + 10];
int b[127 + 10] = {0};
int main()
{
	int i = 1, j = 1, sum = 0;
	gets(a);
	int n = strlen(a);
	for (i = 0; i < n; i++) {
		b[a[i]]++;
	}
	for (i = 0; i < n; i++) {
		if (b[a[i]] == 1) {
			printf("%c", a[i]);
			return 0;
		}
	}
	printf("no");
	return 0;
}
