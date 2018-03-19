#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
void dfs(int i, int j)
{
	a[i][j] = 0;
	for (int k = -1; k <= 1; ++k) {
		for (int h = -1; h <= 1; ++h) {
			if (a[i + k][j + h] == 255) dfs(i + k, j + h);
		}
	}
}
int main()
{
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((i == 1 || i == n || j == 1 || j == n) && a[i][j] == 255) dfs(i, j);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] == 255) sum++;
		}
	}

	cout << sum << endl;
	return 0;
}