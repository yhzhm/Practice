// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int a[11][11], b[11][11];
void print(int a[11][11])
{
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
void cp(int a[11][11], int b[11][11])
{
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j) {
			a[i][j] = b[i][j];
			b[i][j] = 0;
		}
}
void grow(int a[11][11], int b[11][11])
{
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j) {
			for (int k = -1; k <= 1; ++k)
				for (int h = -1; h <= 1; ++h) {
					if (k == 0 && h == 0) b[i][j] += a[i][j] * 2;
					else b[i + k][j + h] += a[i][j];
				}
		}
}
int main()
{
	int m, n;
	cin >> m >> n;
	a[5][5] = m;
	for (int i = 1; i <= n; ++i)
	{
		grow(a, b);
		cp(a, b);
	}
	print(a);
	return 0;
}
