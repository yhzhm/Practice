// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	cin >> m;
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		if (binary_search(a + i + 1, a + n, m - a[i])) {//利用binary_search查找m-a[i]
			printf("%d %d\n", a[i], m - a[i]);
			return 0;
		}
	}
	printf("No\n");
	return 0;
}