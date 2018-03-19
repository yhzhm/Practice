// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	n = (2 * n - 1);
	int a[50][50];
	memset(a, 0, sizeof(a));
	int i = 1, j = n / 2 + 1;
	for (int x = 1; x <= n * n; ++x) {
		a[i][j] = x;
		if ((i == 1 && j == n) || a[i - 1][j + 1] != 0) {i++; continue;}
		if (i == 1) {i = n; j++; continue;}
		if (j == n) {j = 1; i--; continue;}
		i--; j++;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}