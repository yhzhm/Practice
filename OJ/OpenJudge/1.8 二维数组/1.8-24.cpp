// Created by Hz Yang on 2018.03
#include <iostream>
using namespace std;
int main()
{
	int n, i, j, t = 0;
	cin >> n;
	int a[20][20];
	for (int k = 1; k <= n; ++k) {
		if (k % 2) {
			for (j = 1; j <= k; ++j) {
				i = k - j + 1;
				t++;
				a[i][j] = t;
				a[n - i + 1][n - j + 1] = n * n - t + 1;
			}
		}
		else {
			for (j = k; j >= 1; --j) {
				i = k - j + 1;
				t++;
				a[i][j] = t;
				a[n - i + 1][n - j + 1] = n * n - t + 1;
			}
		}
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}