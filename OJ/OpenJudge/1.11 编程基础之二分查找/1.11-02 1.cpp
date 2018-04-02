// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
double f(double x) {
	return pow(x, 5) - 15 * pow(x, 4) + 85 * pow(x, 3) - 225 * x * x + 274 * x - 121;
}
int main()
{
	double l, r, mid;
	l = 1.5; r = 2.4;
	while (r - l > 0.00000005) {
		mid = (l + r) / 2;
		if (f(mid) < 0) r = mid;
		else l = mid + 0.00000005;
	}
	cout << fixed << setprecision(6) << l << endl;
	return 0;
}