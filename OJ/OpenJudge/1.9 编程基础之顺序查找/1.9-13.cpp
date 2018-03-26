// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n], b[101] = {0};
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (!b[a[i]]) {cout << a[i] << ' '; b[a[i]] = 1;}
	}
	return 0;
}