// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
const double INF = 1e10;
struct Point
{
	double x, y;
	bool type;
	bool operator < (const Point &w) const {
		return x < w.x;
	}
} points[M], temp[M];

double dist(Point a, Point b)
{
	if (a.type == b.type) return INF;
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

double dfs(int l, int r)
{
	if (l >= r) return INF;//直接返回正无穷

	int mid = l + r >> 1;//当前区间的中点
	double mid_x = points[mid].x;//中线
	double res = min(dfs(l, mid), dfs(mid + 1, r));//递归左右两个区间

	{	//将左右两个按y排好序的区间归并成一个按y排序的区间
		int k = 0, i = l, j = mid + 1;
		/*while (i <= mid && j <= r)
			if (points[i].y < points[j].y) temp[k++] = points[i++];
			else temp[k++] = points[j++];
		while (i <= mid) temp[k++] = points[i++];
		while (j <= r) temp[k++] = points[j++];
		//归并排序后复制回原数组
		for (int i = 0, j = l; i < k; i++, j++) points[j] = temp[i];*/
		for (k = l; k <= r; ++k)
			if (j > r || points[i].y < points[j].y) temp[k] = points[i++];
			else temp[k] = points[j++];
		for (k = l; k <= r; ++k) points[k] = temp[k];
	}

	int k = 0;//找出距离区间中线res（两侧的虚线内）的所有点（已经按y排好序）
	for (int i = l; i <= r; i++)
		if (points[i].x >= mid_x - res && points[i].x <= mid_x + res)
			temp[k++] = points[i];
	for (int i = 0; i < k; ++i)//枚举窗口内的每个点（最多有6个）
		for (int j = i - 1; j >= 0 && temp[i].y - temp[j].y <= res; j--)
			res = min(res, dist(temp[i], temp[j]));
	return res;
}

int main()
{
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {//读入核电站坐标
			cin >> points[i].x >> points[i].y;
			points[i].type = 0;
		}
		for (int i = n; i < n * 2; ++i) {//读入特工坐标
			cin >> points[i].x >> points[i].y;
			points[i].type = 1;
		}

		sort(points, points + n * 2);//按横坐标排序

		printf("%.3f\n", dfs(0, n * 2 - 1));//递归第一个点到最后一个点
	}
	return 0;
}