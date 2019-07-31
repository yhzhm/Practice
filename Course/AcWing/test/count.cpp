// Created by Hz Yang on 2019.06
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int f[N], sum, maxn, minn = 110;
int main()
{
	cout << minn << endl;
	int n, m, x;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> x;
			if (x == 0) sum++, f[i]++;
		}
	int maxi, mini;
	for (int i = 1; i <= n; ++i) {
		if (f[i] > maxn) maxn = f[i], maxi = i;
		if (f[i] < minn) minn = f[i], mini = i;
	}
	cout << sum << ' ' << maxi << ' ' << mini << endl;
	return 0;
}