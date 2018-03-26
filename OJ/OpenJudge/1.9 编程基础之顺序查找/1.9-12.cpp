// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n + 1] = {0};
	int maxn = 0, count = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != a[i - 1]) {
			maxn = max(maxn, count);
			count = 1;
		} else count++;
	}
	cout << max(maxn, count) << endl;
	return 0;
}