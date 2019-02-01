// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll b[N], c[N], s[N];
ll n, m, t, i, j, x, y;
ll calc(ll a[N], int n)
{
	ll ans = 0, avg = a[0] / n;//a[]的平均值
	for (int i = 1; i <= n; ++i) {
		a[i] -= avg;
		s[i] = s[i - 1] + a[i];//求a[i]减平均数后的前缀和
	}
	sort(s + 1, s + n + 1);//排序
	ll z = s[n >> 1 | 1];//求中位数
	for (int i = 1; i <= n; ++i) ans += abs(s[i] - z);//用仓库选址问题的方法，解决环形纸牌问题
	return ans;
}
int main()
{
	cin >> n >> m >> t;
	for (int i = 1; i <= t; ++i) {
		scanf("%lld%lld", &x, &y);
		b[x]++;
		c[y]++;
	}
	for (int i = 1; i <= n; ++i) b[0] += b[i];
	for (int i = 1; i <= m; ++i) c[0] += c[i];
	if (b[0] % n == 0 && c[0] % m == 0)
		printf("both %lld\n", calc(b, n) + calc(c, m));
	else if (b[0] % n == 0)
		printf("row %lld\n", calc(b, n));
	else if (c[0] % m == 0)
		printf("column %lld\n", calc(c, m));
	else puts("impossible");

	return 0;
}