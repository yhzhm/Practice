// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x[2010] = {0}, a[1010], b[1010], maxn = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i) {
		for (int j = a[i]; j < b[i]; ++j) {
			x[j]++;
		}
	}
	for (int i = 0; i <= 2000; ++i) {
		if (maxn < x[i]) maxn = x[i];
	}
	cout << maxn << endl;
	return 0;
}