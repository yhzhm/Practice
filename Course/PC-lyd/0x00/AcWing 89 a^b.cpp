// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, p;
	cin >> a >> b >> p;
	int res = 1 % p;
	while (b) {
		if (b & 1) res = res * 1ll * a % p;
		a = a * 1ll * a % p;
		b >>= 1;
	}
	cout << res << endl;
	return 0;
}