// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x;
	cin >> n;
	vector<int> v;
	v.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	cin >> x;
	for (int i = 1; i <= n; ++i) {
		if (v[i] == x) {cout << i; return 0;}
	}
	cout << -1;
	return 0;
}