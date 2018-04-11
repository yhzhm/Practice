// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int a[105][105], b[105][105];
int m, n, r, s, sum, u, v, minn = 1000000000;

int check(int x, int y)
{
	int sum = 0;
	for (int i = x, k = 0; i < x + r; ++i, ++k) {
		for (int j = y, l = 0; j < y + s; ++j, ++l) {
			sum += abs(a[i][j] - b[k][l]);
		}
	}
	return sum;
}
void print(int x, int y)
{
	for (int i = x; i < x + r; ++i) {
		for (int j = y; j < y + s; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	cin >> r >> s;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < s; ++j) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i <= m - r; ++i) {
		for (int j = 0; j <= n - s; ++j) {
			sum = check(i, j);
			if (minn > sum ) {
				minn = sum;
				u = i; v = j;
			}
		}
	}
	print(u, v);
	return 0;
}