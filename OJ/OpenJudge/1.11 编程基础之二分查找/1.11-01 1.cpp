// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, x, l, r, mid;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		if (a[0] > x) {cout << a[0] << endl; continue;}
		if (a[n - 1] < x) {cout << a[n - 1] << endl; continue;}
		l = 0; r = n - 1;
		while (l < r) {
			mid = (l + r) / 2;
			if (a[mid] >= x) r = mid;
			else l = mid + 1;
		}
		if (a[l] == x) {cout << a[l] << endl; continue;}
		else cout << (a[l] - x < x - a[l - 1] ? a[l] : a[l - 1]) << endl;
	}
	return 0;
}