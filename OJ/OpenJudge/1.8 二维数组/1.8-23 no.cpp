// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int row, col;
	cin >> row >> col;
	int a[110][110];
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> a[i][j];
		}
	}
	int i = 0, j = -1, d = 0;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for (int t = 1; t <= row * col; ++t) {
		i += dx[d]; j += dy[d];
		cout << a[i][j] << endl;
		if (i + dx[d] == row || j + dy[d] == col || j + dy[d] == 0 || a[i + dx[d]][j + dy[d]] != 0) {d = (d + 1) % 4;}
	}
	return 0;
}