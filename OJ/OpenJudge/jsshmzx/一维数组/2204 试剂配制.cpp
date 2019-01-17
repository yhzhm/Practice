// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int a[9];
bool check() {
	if ((a[1] && a[2]) || (a[3] && a[4])) return 0;
	if (a[5]^a[6]) return 0;
	if (!(a[7] || a[8])) return 0;
	return 1;
}
int main()
{
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		a[x] = 1;
	}
	cout << check() << endl;
	return 0;
}