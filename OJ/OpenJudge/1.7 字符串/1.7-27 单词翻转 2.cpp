/*27:单词翻转
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个句子（一行），将句子中的每一个单词翻转后输出。

输入
只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。
输出
翻转每一个单词后的字符串，单词之间的空格需与原文一致。
样例输入
hello world
样例输出
olleh dlrow*/

// Created by Hz Yang on 2017.04
// Output Limit Exceeded
/*#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	while (cin.peek() != '\n') {
		cin >> s;
		reverse(s.begin(), s.end());
		cout << s << ' ';
	}
	return 0;
}*/
