// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int n, sum1 = 0, sum2 = 0;
int a[110][110];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool check(int x, int y)
{
	for (int d = 0; d < 4; ++d) {
		if (x == 1 || x == n || y == 1 || y == n || a[x + dx[d]][y + dy[d]] > 50) return true;
	}
	return false;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] <= 50) sum1++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] <= 50 && check(i, j)) sum2++;
		}
	}
	cout << sum1 << ' ' << sum2 << endl;
	return 0;
}