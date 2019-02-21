// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9;
ll a[60010], c[120010];
int n, p;

void factor(int n, int cnt)//分解质因数，统计在c[]中，分母cnt=1，分子cnt=-1
{
	for (int i = 2; i * i <= n; ++i)
		while (n % i == 0) c[i] += cnt, n /= i;
	if (n) c[n] += cnt;
}

void calc(ll x)//计算，所有因数相乘
{
	for (int i = 1; i <= p; ++i) a[i] *= x;
	for (int i = 1; i <= p; ++i) a[i + 1] += a[i] / M, a[i] %= M;
	while (a[p + 1]) ++p;
}

int main()
{
	a[1] = p = 1; cin >> n;
	for (int i = 2; i <= n; ++i) factor(n + i, 1), factor(i, -1);//n+2~n+n的因素+1统计，2~n的因数-1统计
	for (int i = 2; i <= n << 1; ++i)//将所有剩余因数相乘
		for (ll j = 0; j < c[i]; ++j) calc(i);
	printf("%lld", a[p]);//输出
	for (int i = p - 1; i; --i) printf("%09lld", a[i]);
	puts("");
	return 0;
}