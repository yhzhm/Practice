// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
struct rec//点x,y坐标，z标识点的类别
{
	int x, y, z;
} a[200010], b[200010];
int n;
double ans;

bool cmp(rec &a, rec &b)
{
	return a.x < b.x;
}

double dist(rec &a, rec &b)//计算两点距离
{
	return sqrt(double(a.x - b.x) * (a.x - b.x) + double(a.y - b.y) * (a.y - b.y));
}

void merge(int l, int mid, int r)//根据点y坐标从小到大归并排序
{
	int i = l, j = mid + 1, k;
	for (k = l; k <= r; ++k) {
		if (j > r || a[i].y < a[j].y) b[k] = a[i++];
		else b[k] = a[j++];
	}
	for (k = l; k <= r; k++) a[k] = b[k];
}

void solve(int l, int r)
{
	if (l == r) return;//边界，1个点不能再分
	int mid = (l + r) >> 1, p = 0, x = a[mid].x;
	solve(l, mid);
	solve(mid + 1, r);
	merge(l, mid, r);//根据y坐标从小到大归并排序
	for (int i = l; i <= r; ++i) {//找出到中线x距离小于ans的所有点
		if (abs(a[i].x - x) <= ans) b[++p] = a[i];
	}
	for (int i = 1; i < p; ++i)
		for (int j = i + 1; j <= p; ++j) {
			if (b[j].y - b[i].y < ans) {//若两点y距离小于ans且类别不同，计算点距
				if (b[i].z != b[j].z) ans = min(ans, dist(b[i], b[j]));
			} else break;//因为已根据y排序，所以剩余点距i点的y距离只会越来越大，故及时剪枝
		}
}

int main()
{
	int t, i; cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y), a[i].z = 1;
		for (i = n + 1, n *= 2; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y), a[i].z = 2;
		ans = dist(a[1], a[n]);//取第一个点和最后一个点的距离作为初始值
		sort(a + 1, a + n + 1, cmp);//将所有点根据x坐标从小到大排序
		solve(1, n);//区域对分
		printf("%.3f\n", ans);
	}
	return 0;
}