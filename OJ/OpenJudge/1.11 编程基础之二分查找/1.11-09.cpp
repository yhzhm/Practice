// Created by Hz Yang on 2018.04
#include<bits/stdc++.h>
using namespace std;
double x = 0, y = asin(1.0), l, L, n, c, mid;
int main()
{
	cin >> l >> n >> c;
	L = (1 + n * c) * l;
	if (l * n * c == 0) {printf("0.000"); return 0;}
	for (int i = 0; i < 36000; i++)
	{
		mid = (x + y) / 2;
		if (mid * (l / sin(mid)) >= L)y = mid;
		else x = mid;
	}
	printf("%.3lf\n", L / (2 * x) * (1 - cos(y)));
	return 0;
}