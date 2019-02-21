// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 10;
int a[M][M], s[M][M], C, N, maxn, ans = M;
int main()
{
	scanf("%d%d", &C, &N);
	int x, y;
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &x, &y);
		a[x][y]++;
		maxn = max(maxn, x > y ? x : y);
	}
	// cout << maxn << endl;

	for (int i = 1; i <= maxn; ++i) {
		for (int j = 1; j <= maxn; ++j) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
			// cout << s[i][j] << ' ';
		}
		// cout << endl;
	}
	for (int i = 1; i <= maxn; ++i) {
		for (int j = 1; j <= maxn; ++j) {
			for (int k = 0; i + k <= maxn && j + k <= maxn; ++k) {
				int now = i + k;
				int sum = s[now][now] - s[i - 1][now] - s[now][j - 1] + s[i][j - 1];
				// cout << sum << ' ';
				if (sum >= C) {ans = min(ans, k + 1); break;}
			}
		}
	}
	cout << ans << endl;
	return 0;
}