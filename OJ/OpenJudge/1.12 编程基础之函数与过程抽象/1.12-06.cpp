// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a, b;
};
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	node a[n][m];
	int cnt[10005] = {0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d%d", &a[i][j].a, &a[i][j].b);
			if (a[i][j].a) cnt[i]++;
		}
	}
	int x, z, sum = 0; cin >> x;
	for (int i = 0; i < n; ++i) {
		sum += a[i][x].b % 20123;
		z = (a[i][x].b % cnt[i]);
		if (!z) z = cnt[i];
		if (a[i][x].a) z--;
		while (z > 0) {
			x++;
			if (x == m) x = 0;
			if (a[i][x].a) z--;
		}
	}
	printf("%d\n", sum % 20123);
	return 0;
}