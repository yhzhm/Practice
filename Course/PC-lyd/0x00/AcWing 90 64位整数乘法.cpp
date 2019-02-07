// Created by Hz Yang on 2019.01
#include <iostream>
using namespace std;
typedef unsigned long long ull;
int main()
{
	ull a, b, p;
	cin >> a >> b >> p;
	ull res = 0;
	while (b) {
		if (b & 1) res = (res + a) % p;
		a = (a << 1) % p;
		b >>= 1;
	}
	cout << res << endl;
	return 0;
}