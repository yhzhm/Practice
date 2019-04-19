// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int M = 50010;
int n, sum, ans = INT_MIN; //ans初始值要注意，答案有负数
PII cows[M];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int w, s;
		cin >> w >> s;
		cows[i] = {w + s, w};
	}
	sort(cows, cows + n);
	for (int i = 0; i < n; ++i) {
		int w = cows[i].second, s = cows[i].first - w;
		ans = max(ans, sum - s);
		sum += w;
	}
	cout << ans << endl;
	return 0;
}

/*
贪心 微扰，可用书中方法证明，根据w和s之和从小到大排序后，结果最优
接下来就是求最优状态下的最大值。
 */