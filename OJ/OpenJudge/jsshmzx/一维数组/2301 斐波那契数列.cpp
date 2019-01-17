// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x, a[25];
	a[1] = a[2] = 1;
	for (int i = 3; i <= 20; ++i) {
		a[i] = a[i - 1] + a[i - 2];
	}
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		cout << a[x] << endl;
	}
	return 0;
}