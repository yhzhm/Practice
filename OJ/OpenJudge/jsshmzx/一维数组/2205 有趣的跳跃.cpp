// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x, a[3010], b[3010] = {0};
	cin >> n;
	cin >> a[1];
	for (int i = 2; i <= n; ++i) {
		cin >> a[i];
		x = abs(a[i] - a[i - 1]);
		b[x]++;
	}
	bool flag = 1;
	for (int i = 1; i < n; ++i) {
		if (b[i] == 1) continue;
		else {
			flag = 0;
			break;
		}
	}
	if (flag) cout << "Jolly" << endl;
	else cout << "Not jolly" << endl;
	return 0;
}