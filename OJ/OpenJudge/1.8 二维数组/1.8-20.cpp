// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
char a[110][30];
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int t = s.size() / n;
	int p = -1;
	for (int i = 1; i <= t; ++i) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; ++j) a[i][j] = s[++p];
		}
		else {
			for (int j = n; j >= 1; --j) a[i][j] = s[++p];
		}
	}
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= t; ++i) {
			cout << a[i][j];
		}
	}
	cout << endl;
	return 0;
}