// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
const int M = 1010;
int x1, y1, x2, y2, t;
string st[M], s1, s2, x;

bool check(string s2)
{
	int x = x1 - x2, y = y1 - y2;
	string s;
	// cout << s2 << endl;
	for (int i = 0; i <= x; ++i) {
		for (int j = 0; j <= y; ++j) {
			s = "";
			for (int k = i; k < i + x2; ++k) {
				s += st[k].substr(j, y2);
			}
			// cout << s << endl;
			if (s2 == s) return true;
		}
	}
	return false;
}

int main()
{
	cin >> x1 >> y1 >> x2 >> y2;
	for (int i = 0; i < x1; ++i) cin >> st[i];
	cin >> t;
	while (t--) {
		s2 = "";
		for (int i = 0; i < x2; ++i)
			cin >> x, s2 += x;
		cout << check(s2) << endl;
	}
	return 0;
}

/*
string 超时
 */