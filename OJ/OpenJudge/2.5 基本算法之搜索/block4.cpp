#include<bits/stdc++.h>
using namespace std;
int m, n;
char a[255][255];
bool check(int x, int y) {
	if (x < 1 || y < 1 || x > m || y > n) return 0;
	return 1;
}
void dfs(int x, int y) {
	if (check(x, y) && a[x][y] == '.') {
		a[x][y] = '#';
		dfs(x, y + 1);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x - 1, y);
	}
}
int main() {
//	freopen("block.in","r",stdin);
//	freopen("block.out","w",stdout);
	cin >> m >> n;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	int ret = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i][j] == '.') {
				dfs(i, j);
				ret++;
			}
	cout << ret;
	fclose(stdin); fclose(stdout);
	return 0;
}
