// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int check(string s) {
	int maxx = 0, x = 0;
	s = s + ',';
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != ',') x = x * 10 + (s[i] - 48);
		else {
			maxx = max(maxx, x);
			x = 0;
		}
	}
	return maxx;
}
int main()
{
	int n;
	cin >> n;
	string x;
	int b[n] = {0}, maxn = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		b[i] = check(x);
		maxn = max(maxn, b[i]);
	}
	cout << maxn << endl;
	bool first = 1;
	for (int i = 0; i < n; ++i) {
		if (maxn == b[i]) {
			if (first) {cout << i + 1; first = 0;}
			else cout << ',' << i + 1;
		}
	}
	return 0;
}