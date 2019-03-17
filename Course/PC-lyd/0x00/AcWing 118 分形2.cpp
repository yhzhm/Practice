// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 10;
char g[M][M];
void dfs(int n)
{
	if (n == 1) {
		g[0][0] = 'X';
		return;
	}
	dfs(n - 1);
	int len = 1;
	for (int i = 0; i < n - 2; ++i) len *= 3;//计算n-2级图形的边长：3的n-2次方
	int sx[4] = {0, 1, 2, 2}, sy[4] = {2, 1, 0, 2};//用n-1级图形构造n级图形（复制到相应位置）
	for (int k = 0; k < 4; ++k)
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < len; ++j)
				g[sx[k]*len + i][sy[k]*len + j] = g[i][j];
}
int main()
{
	dfs(7);//构造好7级的图形，然后选择需要的大小输出（左上角）

	int n;
	while (cin >> n, n != -1) {
		int len = 1;
		for (int i = 0; i < n - 1; ++i) len *= 3;//计算3的n-1次方
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < len; ++j)
				if (g[i][j]) cout << 'X';
				else cout << ' ';
			cout << endl;
		}
		cout << '-' << endl;
	}
	return 0;
}