// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], l, r, mid;
bool check(int mid)
{
	int sum = 0, count = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > mid) return false;
		if (sum + a[i] <= mid) {sum += a[i];}
		else {sum = a[i]; count++;}
	}
	return count <= m;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		r += a[i];
	}
	while (r > l) {
		mid = l + (r - l) / 2;
		printf("%d %d %d\n", l, r, mid);
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}