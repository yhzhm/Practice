// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 5;
int a[M][M], d[M], n, ans;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) cin >> a[i][j];
	for (int i = 0; i < n; ++i) {//枚举起始行
		memset(d, 0, sizeof d);
		for (int j = i; j < n; ++j) {//分列求和
			for (int k = 0; k < n; ++k) d[k] += a[j][k];
			int sum = 0;
			for (int k = 0; k < n; ++k) {
				sum += d[k];
				ans = max(ans, sum);
				if (sum < 0) sum = 0;//小于0的列，舍弃
			}
		}
	}
	cout << ans << endl;
	return 0;
}