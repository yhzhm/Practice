// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m;
int cows[N];
double sum[N];
bool check(double avg)
{
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + cows[i] - avg;
	double minv = 0;
	for (int i = 0, j = m; j <= n; ++j, ++i) {
		minv = min(minv, sum[i]);
		if (sum[j] >= minv) return true;
	}
	return false;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> cows[i];
	double l = 0, r = 2000;
	while (r - l > 1e-5) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << int(r * 1000);
	return 0;
}
/*
暗含条件：答案下取整
有关平均值的一个常用技巧，就是将所有值都减去一个相同的值
问题就变成判断子序列的和是否非负
1.最优化->判定
2.平均值->非负性
3.区间->双指针


 */