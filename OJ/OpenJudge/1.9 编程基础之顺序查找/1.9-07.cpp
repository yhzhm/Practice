// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a[101], maxn = 0, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == maxn) continue;
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}