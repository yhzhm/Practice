// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[1010];
	int n;
	cin >> n >> a[1];
	int sum = 0, maxn = 0;
	for (int i = 2; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > a[i - 1]) sum += a[i] - a[i - 1];
		else {
			maxn = max(sum, maxn);
			sum = 0;
		}
	}
	cout << max(sum, maxn);
	return 0;
}