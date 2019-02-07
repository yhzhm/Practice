// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], sum;
int main()
{
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	x = a[n >> 1 | 1];
	// if (n % 2) x = a[(n + 1) / 2];
	// else x = a[n / 2];
	for (int i = 1; i <= n; ++i) {
		sum += abs(x - a[i]);
	}
	cout << sum << endl;
	return 0;
}