// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int x, b[10001] = {0}, maxn = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		b[x]++;
		maxn = max(maxn, x);
	}
	for (int i = 0; i <= maxn; ++i) {
		cout << b[i] << endl;
	}
	return 0;
}