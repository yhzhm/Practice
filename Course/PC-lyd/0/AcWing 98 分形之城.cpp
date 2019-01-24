// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

PLL calc(LL n, LL m)
{
	if (n == 0) return {0, 0};
	LL len = 1ll << (n - 1), cnt = 1ll << (2 * n - 2);//子问题中城市长度和房屋数量
	auto pos = calc(n - 1, m % cnt);
	auto x = pos.first, y = pos.second;
	auto z = m / cnt;//子问题位于哪个区间，0左上1右上2右下3左下
	//将子问题的x,y放到当前问题的区间中时，坐标进行相应变换
	if (z == 0) return {y, x};
	if (z == 1) return {x, y + len};
	if (z == 2) return {x + len, y + len};
	return {len * 2 - 1 - y, len - 1 - x};
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		LL N, A, B;
		cin >> N >> A >> B;
		auto ac = calc(N, A - 1);
		auto bc = calc(N, B - 1);
		double x = ac.first - bc.first, y = ac.second - bc.second;
		printf("%.0lf\n", sqrt(x * x + y * y) * 10);
	}
	return 0;
}

/*
点x,y顺时针旋转θ度：     90°			-90°=270°
(x,y) * [cosθ sinθ]		[ 0 1 ]   	[ 0 -1 ]
        -sinθ cosθ		 -1 0         1  0
顺时针90°：(-y,x)  再水平翻转：(y,x)
逆时针90°：(y,-x)  在水平翻转：(-y,-x)
 */