// Created by Hz Yang on 2018.04
#include<bits/stdc++.h>
using namespace std;
int l, n, m, a[50005], L;
int check(int x)
{
	int last = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] - last < x)ans++;
		else last = a[i];
	}
	return ans <= m;
}
int main()
{
	cin >> L >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[++n] = L;
	int l = 0, r = L, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", l - 1);
}