// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n, sum, ans = -0x7fffffff; //ans初始值要注意，答案有负数
pll cow[50010];

bool cmp(pll &a, pll &b)
{
	return (a.first + a.second) < (b.first + b.second);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &cow[i].first, &cow[i].second);
	// if (n == 1) {cout << -cow[0].second << endl; return 0;}
	sort(cow, cow + n, cmp);
	for (int i = 0; i < n; ++i) {
		ans = max(ans, sum - cow[i].second);//两句交换了顺序，可以不考虑n==1的情况
		sum += cow[i].first;
	}
	cout << ans << endl;
	return 0;
}

/*
贪心 微扰，可用书中方法证明，根据w和s之和从小到大排序后，结果最优
接下来就是求最优状态下的最大值。
 */