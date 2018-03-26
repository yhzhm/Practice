// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int c[10000][10000];
int main()
{
	int n;
	cin >> n;
	int a, b, x, y;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b >> x >> y;
		for (int j = a; j <= a + x; ++j) {
			for (int k = b; k <= b + y; ++k) {
				c[j][k] = i;
			}
		}
	}
	cin >> x >> y;
	if (c[x][y]) cout << c[x][y] << endl;
	else cout << -1;
	return 0;
}