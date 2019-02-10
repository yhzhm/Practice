// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
#define l first
#define r second
#define point pair<double, double>//记录点x坐标y坐标

int N; double D;//N岛的数量、D雷达范围
point p[1010];//记录岛的坐标
int cnt = 1;//记录雷达数量

bool check(double px, double py)//判断岛的坐标是否在雷达范围内、是否合法
{
	if (py > D || py < 0) return false;
	return true;
}
//根据岛的坐标，计算雷达可安置的范围，保存于point p[]中
void getx(double px, double py, double &le, double &ri)
{
	double m = sqrt(D * D - py * py);
	le = px - m; ri = px + m;
}

bool cmp(point x, point y)
{
	// return x.l == y.l ? x.r < y.r : x.l < y.l;
	//按照r从小到大排序，可省略line 47：tmp = min(p[i].r, tmp);判断
	return x.r == y.r ? x.l < y.l : x.r < y.r;
}

int main()
{
	cin >> N >> D;
	double px, py;
	for (int i = 1; i <= N; ++i) {
		cin >> px >> py;
		if (!check(px, py)) {cout << -1 << endl; return 0;}
		getx(px, py, p[i].l, p[i].r);
	}
	sort(p + 1, p + N + 1, cmp);
	double tmp = p[1].r;
	for (int i = 2; i <= N; ++i) {
		if (p[i].l > tmp) {//若左端点大于最后一台雷达的坐标，则新增一台设备
			cnt++;
			tmp = p[i].r;
		}
		// else tmp = min(p[i].r, tmp);
	}
	cout << cnt << endl;
	return 0;
}