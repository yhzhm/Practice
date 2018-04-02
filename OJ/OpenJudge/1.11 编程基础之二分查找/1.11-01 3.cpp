// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, x;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x;
		int* p = lower_bound(a, a + n, x);
		if (x == *p) cout << *p << endl;
		else {
			if (p == a) {cout << *p << endl; continue;}
			if (p == a + n) {cout << *(p - 1) << endl; continue;}
			cout << (*p - x < x - * (p - 1) ? *p : * (p - 1)) << endl;
		}
	}
	return 0;
}