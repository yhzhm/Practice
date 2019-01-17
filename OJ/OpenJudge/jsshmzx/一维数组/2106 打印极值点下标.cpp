// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[100], n, k;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> a[j];
		}
		if (a[1] > a[2] || a[1] < a[2]) cout << 0 << ' ';
		for (int j = 2; j < k; ++j) {
			if ((a[j] > a[j - 1] && a[j] > a[j + 1]) || (a[j] < a[j - 1] && a[j] < a[j + 1]))
				cout << j - 1 << ' ';
		}
		if (a[k] > a[k - 1] || a[k] < a[k - 1]) cout << k - 1 << ' ';
		cout << endl;
	}
	return 0;
}