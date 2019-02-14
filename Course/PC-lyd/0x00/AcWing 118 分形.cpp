// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
bool a[2200][2200];//保存图形
int edge[10];//预先计算好图形边长
void dfs(int n, int x, int y)//n级图形左上角的x,y轴坐标
{
	if (n == 1) {
		a[x][y] = 1;
		return;
	}
	int e = edge[n - 1];
	dfs(n - 1, x, y); //左上角
	dfs(n - 1, x + 2 * e, y); //右上角
	dfs(n - 1, x + e, y + e); //中间
	dfs(n - 1, x, y + 2 * e); //左下角
	dfs(n - 1, x + 2 * e, y + 2 * e); //右下角
}
void print(int n)
{
	for (int i = 1; i <= edge[n]; ++i) {
		for (int j = 1; j <= edge[n]; ++j) {
			if (a[i][j]) cout << 'X';
			else cout << ' ';
		}
		cout << endl;
	}
	cout << '-' << endl;
}

int main()
{
	edge[1] = 1;
	for (int i = 2; i <= 7; ++i) edge[i] = edge[i - 1] * 3;//预处理n级图的边长
	int n;
	while (cin >> n) {
		if (n == -1) break;
		dfs(n, 1, 1);//n级，1,1为图形左上角x轴y轴坐标
		print(n);
	}
	return 0;
}