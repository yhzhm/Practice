// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
char a[110][30];
int main()
{
	int n, i, j;
	cin >> n;
	string s;
	cin >> s;
	int t = s.size() / n;
	int p = -1;
	for (int x = 0; x < s.size(); ++x) {
		i = x / n;
		j = x % n;
		if (i % 2 == 1) j = n - j - 1;
		a[i][j] = s[x];
	}
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < t; ++i) {
			cout << a[i][j];
		}
	}
	cout << endl;
	return 0;
}