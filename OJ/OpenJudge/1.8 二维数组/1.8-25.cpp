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
	string::size_type p = 0;
	for (string::size_type i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') p++;
		else break;
	}
	s.erase(0, p);
	for (string::size_type i = 0; i < s.size(); ++i) {
		sum += change(s[i]);
	}
	int a[25][25], b[25][25];
	memset(a, 0, sizeof(a));
	memset(b, -1, sizeof(b));
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			b[i][j] = 0;
		}
	}
	int i = 1, j = 1, d = 0;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for (int k = 0; k < sum.size(); ++k) {
		a[i][j] = sum[k] - '0';
		b[i][j] = -1;
		if (b[i + dx[d]][j + dy[d]] != 0) {++d; d = d % 4;}
		i += dx[d]; j += dy[d];
	}
	for (i = 1; i <= row; ++i) {
		for (j = 1; j <= col; ++j) {
			cout << a[i][j];
		}
	}
	return 0;
}
