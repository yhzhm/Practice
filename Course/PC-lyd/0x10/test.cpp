// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
const int M = 105;
typedef pair<double, double> PDD;
PDD a[M];
int n, t;
int f(int x, int y, int n)
{
	switch (n) {
	case 1: return x + y; break;
	case 2: return x - y; break;
	case 3: return x * y; break;
	case 4: return x / y; break;
	default: return 0;
	}
}
int main()
{
	int a, b, c, d, e, ans = 0;
	cin >> a >> b >> c >> d >> e;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++) {
				if (f(f(f(a, b, i), c, j), d, k) == e) ans++;
			}
	cout << ans << endl;
	return 0;
}