// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 5;
int a[M][M], n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			a[i][j] += a[i - 1][j];
		}
	int res = INT_MIN;
	for (int i = 1; i <= n; ++i) {//枚举起始行
		for (int j = i; j <= n; ++j) {
			int last = 0;
			for (int k = 1; k <= n; ++k) {
				last = max(last, 0) + a[j][k] - a[i - 1][k];
				res = max(res, last);
			}
		}
	}
	cout << res << endl;
	return 0;
}