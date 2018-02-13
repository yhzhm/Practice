/*25:最长最短单词
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入1行句子（不多于200个单词，每个单词长度不超过100），只包含字母、空格和逗号。单词由至少一个连续的字母构成，空格和逗号都是单词间的间隔。

试输出第1个最长的单词和第1个最短单词。

输入
一行句子。
输出
两行输出：
第1行，第一个最长的单词。
第2行，第一个最短的单词。
样例输入
I am studying Programming language C in Peking University
样例输出
Programming
I*/

// Created by Hz Yang on 2017.03
#include <bits/stdc++.h>
using namespace std;
char a[200000];
int main()
{
	gets(a);
	int len = strlen(a);
	int sum = 0, max = 0, min = 1000, posmax = 0, posmin = 0;
	for (int i = 0; i <= len; ++i)
	{
		if (a[i] != ' ' && a[i] != ',' && a[i] != '\0') sum++;
		else if (sum > 0) {
			if (max < sum) {max = sum;  posmax = i;}
			if (min > sum) {min = sum;  posmin = i;}
			sum = 0;
		}
	}
	for (int i = posmax - max; i < posmax; ++i)
		cout << a[i];
	cout << endl;
	for (int i = posmin - min; i < posmin; ++i)
		cout << a[i];
	cout << endl;
	return 0;
}