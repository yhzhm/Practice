// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], n;
string s;
string change()
{
	string result = "";
	for (int i = 1; i <= n; ++i) {
		result += (char)(b[i] + '0');
	}
	return result;
}
int main()
{
	cin >> s;
	string ss = s + s;
	n = s.size();
	for (int i = 0; i < s.size(); ++i) {
		a[i + 1] = s[i] - '0';
	}
	for (int i = 1; i <= n; ++i) {
		memset(b, 0, sizeof(b));
		for (int j = n; j >= 1; --j) {
			b[j] += a[j] * i;
			b[j - 1] = b[j] / 10;
			b[j] %= 10;
		}
		string x = change();//转换成string判断虽然耗费时间，但一次失败就可提前结束。
		if (ss.find(x) == string::npos) {cout << 0 << endl; return 0;}
	}
	cout << 1 << endl;
	return 0;
}