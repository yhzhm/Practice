// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int x, b[101] = {0};
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (!b[x]) {cout << x << ' '; b[x] = 1;}
	}
	return 0;
}