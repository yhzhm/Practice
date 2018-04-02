// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, x;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x;
		vector<int>::iterator p = lower_bound(v.begin(), v.end(), x);
		if (x == *p) cout << *p << endl;
		else {
			// if (p == v.begin()) {cout << *p << endl; continue;}
			// if (p == v.end()) {cout << *(p - 1) << endl; continue;}
			cout << (*p - x < x - * (p - 1) ? *p : * (p - 1)) << endl;
		}
	}
	return 0;
}