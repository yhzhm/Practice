#include<bits/stdc++.h>
using namespace std;
int a[105][105], b[105][105], m, n;
void cparr()
{
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = b[i][j];
		}
	}
}
void print()
{
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
void changea(int x, int y)
{
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j) {
			b[j][x - i + 1] = a[i][j];
		}
	}
	swap(m, n);
	cparr();
}
void changeb(int x, int y)
{
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j) {
			b[y - j + 1][i] = a[i][j];
		}
	}
	swap(m, n);
	cparr();
}
void changec(int x, int y)
{
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j) {
			b[i][y - j + 1] = a[i][j];
		}
	}
	cparr();
}
void changed(int x, int y)
{
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j) {
			b[x - i + 1][j] = a[i][j];
		}
	}
	cparr();
}
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		switch (s[i]) {
		case 'A': changea(m, n); break;
		case 'B': changeb(m, n); break;
		case 'C': changec(m, n); break;
		case 'D': changed(m, n); break;
		default: break;
		}
	}
	print();
	return 0;
}
