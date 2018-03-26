// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n], b[10001] = {0}, maxn = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[a[i]]++;
		maxn = max(maxn, a[i]);
	}
	for (int i = 0; i <= maxn; ++i) {
		cout << b[i] << endl;
	}
	return 0;
}