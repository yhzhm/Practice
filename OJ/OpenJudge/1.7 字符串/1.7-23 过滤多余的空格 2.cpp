/*23:过滤多余的空格
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
一个句子中也许有多个连续空格，过滤掉多余的空格，只留下一个空格。

输入
一行，一个字符串（长度不超过200），句子的头和尾都没有空格。
输出
过滤之后的句子。
样例输入
Hello      world.This is    c language.
样例输出
Hello world.This is c language.*/

// Created by Hz Yang on 2017.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while (cin >> s) {
		cout << s << ' ';
	}
	return 0;
}