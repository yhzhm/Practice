// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
string change(char x)
{
	int n = 0;
	if (isupper(x)) n = x - 64;
	string s(5, '0');
	int i = 4;
	while (n > 0) {
		s[i--] = (n % 2) + 48;
		n /= 2;
	}
	return s;
}
int main()
{
	int row, col;
	cin >> row >> col;
	string s, sum = "";
	getline(cin, s);
	for (string::size_type i = 1; i < s.size(); ++i) {
		sum += change(s[i]);
	}
	cout << sum << endl;
	int a[25][25];
	memset(a, -1, sizeof(a));
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i <= row + 1; ++i) {
		for (int j = 0; j <= col + 1; ++j) {
			cout << a[i][j];
		}
		cout << endl;
	}
	int i = 1, j = 1, d = 0;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for (string::size_type k = 0; k < sum.size(); ++k) {
		a[i][j] = sum[k] - '0';
		cout << a[i][j];
	}
	cout << endl;
	for (string::size_type k = 0; k < sum.size(); ++k) {
		a[i][j] = sum[k] - '0';
		cout << a[i][j];
		if (a[i + dx[d]][j + dy[d]] != 0) {++d; d = d % 4;}
		i += dx[d]; j += dy[d];
	}
	cout << endl;

	for (i = 1; i <= row; ++i) {
		for (j = 1; j <= col; ++j) {
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}