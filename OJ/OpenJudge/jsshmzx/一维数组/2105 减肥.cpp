// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[1010] = {0};
	int n;
	cin >> n >> a[1];
	int x = a[1], y = 0, z = 0;
	for (int i = 2; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > a[i - 1]) y = a[i];
		else {
			z = max(z, y - x);
			x = y = a[i];
		}
	}
	cout << max(z, y - x);
	return 0;
}