// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, x;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	cin >> m;
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		if (a[i] >= m) break;
		for (int j = n - 1; j > i; --j) {
			x = a[i] + a[j];
			if (x < m) break;
			if (x == m) {printf("%d %d\n", a[i], a[j]); return 0;}
		}
	}
	printf("No\n");
	return 0;
}