#include <bits/stdc++.h>
using namespace std;
int r, c;
char a[110][110];
void dfs(int i, int j)
{
	a[i][j] = '.';
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	for (int d = 0; d < 4; ++d) {
		if (a[i + dx[d]][j + dy[d]] == '#') dfs(i + dx[d], j + dy[d]);
	}
}
int main()
{
	int sum = 0;
	cin >> r >> c;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (a[i][j] == '#') {
				sum++;
				dfs(i, j);
			}
		}
	}
	cout << sum;
	return 0;
}