// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int row, col;
	int a[110][110];
	cin >> row >> col;
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			cin >> a[i][j];
		}
	}
	for (int t = 1; t <= col; ++t) {
		int i = 1, j = t;
		while (i <= row && j >= 1) {
			cout << a[i][j] << endl;
			i++; j--;
		}
	}
	for (int t = 2; t <= row; ++t) {
		int i = t, j = col;
		while (i <= row && j >= 1) {
			cout << a[i][j] << endl;
			i++; j--;
		}
	}
	return 0;
}