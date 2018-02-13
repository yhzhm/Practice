/*20:删除单词后缀
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个单词，如果该单词以er、ly或者ing后缀结尾， 则删除该后缀（题目保证删除后缀后的单词长度不为0）， 否则不进行任何操作。

输入
输入一行，包含一个单词（单词中间没有空格，每个单词最大长度为32）。
输出
输出按照题目要求处理后的单词。
样例输入
referer
样例输出
refer*/

// Created by Hz Yang on 2017.03
#include <cstdio>
#include <cstring>
using namespace std;
int main ()
{
	char a[32 + 5];
	gets(a);
	int len = strlen(a);
	if (a[len - 1] == 'r' && a[len - 2] == 'e') 						a[len - 2] = '\0';
	if (a[len - 1] == 'y' && a[len - 2] == 'l') 						a[len - 2] = '\0';
	if (a[len - 1] == 'g' && a[len - 2] == 'n' && a[len - 3] == 'i')	a[len - 3] = '\0';
	puts(a);
}