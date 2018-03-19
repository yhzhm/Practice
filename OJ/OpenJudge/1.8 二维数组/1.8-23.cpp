// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int row, col;
	cin >> row >> col;
	int a[110][110];
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			cin >> a[i][j];
		}
	}
	int i = 1, j = 1, d = 0;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for (int t = 1; t <= row * col; ++t) {
		cout << a[i][j] << endl;
		a[i][j] = 0;
		if ( a[i + dx[d]][j + dy[d]] == 0) {d = (d + 1) % 4;}
		i += dx[d]; j += dy[d];
	}
	return 0;
}