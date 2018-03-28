// Created by Hz Yang on 2018.03
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, a[100000], b[100000], g[100000], k[100000], i, t, x, y;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	cin >> x >> y;
	t = 0;
	for (i = 1; i <= n; i++)
		if (x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i]) t = i;
	if (t == 0) cout << -1;
	else cout << t;
	cout << endl;
	return 0;
}