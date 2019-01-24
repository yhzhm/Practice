// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;

const int  N = 5010;
int g[N][N];

int main()
{
	int N, R; //N点的数量，R边长，若和全局变量重名，会优先用主函数的变量
	cin >> N >> R;
	int n = R, m = R;//有时R会比矩形大
	for (int i = 0, x, y, w; i < N; ++i) {
		cin >> x >> y >> w;
		x++, y++; //写前缀和，坐标从1开始比较方便,所以在这里统一加1处理
		n = max(n, x), m = max(m, y); //判断长和宽的边界
		g[x][y] += w;
	}
	//求前缀和，用动态规划的思想
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];

	int res = 0;
	for (int i = R; i <= n; ++i)
		for (int j = R; j <= m; ++j)
			res = max(res, g[i][j] - g[i - R][j] - g[i][j - R] + g[i - R][j - R]);

	cout << res << endl;

	return 0;
}
/*
a[1],a[2], ... ,a[n]
s[i]=a[1] + a[2] + ... + a[i]
a[i] + ... + a[j] = s[j] - s[i-1]
 */