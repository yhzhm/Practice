/*
18:验证子串
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入两个字符串，验证其中一个串是否为另一个串的子串。

输入
输入两个字符串， 每个字符串占一行，长度不超过200且不含空格。
输出
若第一个串s1是第二个串s2的子串，则输出(s1) is substring of (s2)
否则，若第二个串s2是第一个串s1的子串，输出(s2) is substring of (s1)
否则，输出 No substring。
样例输入
abc
dddncabca
样例输出
abc is substring of dddncabca
*/
// Created by Hz Yang on 2017.03
#include <iostream>
#include <cstring>
using namespace std;
string a, b, c;
int main()
{
	cin >> a >> b;
	if (a.find(b) != -1)
		cout << b << " is substring of " << a;
	else if (b.find(a) != -1)
		cout << a << " is substring of " << b;
	else cout << "No substring";
	return 0;
}