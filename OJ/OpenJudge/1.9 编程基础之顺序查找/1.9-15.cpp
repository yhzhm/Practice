// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int c[10000][10000];
int main()
{
	int n, m, w, p, minn;
	cin >> n >> m;
	int t[m + 1] = {0};
	for (int i = 1; i <= n; ++i) {
		cin >> w;
		p = 1; minn = t[1];
		for (int j = 1; j <= m; ++j) {
			if (minn > t[j]) {minn = t[j]; p = j;}
		}
		t[p] += w;
	}
	sort(t + 1, t + m + 1);
	cout << t[m] << endl;
	return 0;
}