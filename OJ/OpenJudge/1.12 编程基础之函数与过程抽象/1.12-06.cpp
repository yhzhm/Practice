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
	int cnt[105] = {0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// cin >> a[i][j].a >> a[i][j].b;
			scanf("%d%d", &a[i][j].a, &a[i][j].b);
			if (a[i][j].a) cnt[i]++;
		}
	}
	int x, z, sum = 0; cin >> x;
	for (int i = 0; i < n; ++i) {
		sum += a[i][x].b % 20123;
		sum %= 20123;
		z = a[i][x].a ? a[i][x].b - 1 : a[i][x].b;
		z = z % cnt[i];
		cin >> n >> m;
		node a[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j].a >> a[i][j].b;
			}
		}
		int x, z, sum = 0; cin >> x;
		for (int i = 0; i < n; ++i) {
			sum += a[i][x].b % 20213;
			sum %= 20123;
			z = a[i][x].a ? a[i][x].b - 1 : a[i][x].b;
			z = (z % cnt[i]) + 1;
			while (z > 0) {
				x++;
				x = x % m;
				if (a[i][x].a) z--;
				// if (a[i][(++x) % m].a) z--;
			}
		}
	}
	// cout << sum << endl;
	printf("%d\n", sum);
	return 0;
}