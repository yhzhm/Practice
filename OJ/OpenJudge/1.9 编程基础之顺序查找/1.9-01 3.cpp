// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x, t;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		v.push_back(t);
	}
	cin >> x;
	for (int i = 0; i < n; ++i) {
		if (v[i] == x) {cout << i + 1; return 0;}
	}
	cout << -1;
	return 0;
}