// Created by Hz Yang on 2017.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, sum = 0, maxd = 0, maxn = 0;
	cin >> n;
	struct st
	{
		string name;
		int sc1, sc2;
		char x1, x2;
		int p = 0, count = 0;
	} a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i].name >> a[i].sc1 >> a[i].sc2 >> a[i].x1 >> a[i].x2 >> a[i].p;
		if (a[i].sc1 > 80 && a[i].p) a[i].count += 8000;
		if (a[i].sc1 > 85 && a[i].sc2 > 80) a[i].count += 4000;
		if (a[i].sc1 > 90) a[i].count += 2000;
		if (a[i].sc1 > 85 && a[i].x2 == 'Y') a[i].count += 1000;
		if (a[i].sc2 > 80 && a[i].x1 == 'Y') a[i].count += 850;
		sum += a[i].count;
		if (maxd < a[i].count) {maxd = a[i].count; maxn = i;}
	}
	cout << a[maxn].name << endl;
	cout << maxd << endl;
	cout << sum << endl;
	return 0;
}