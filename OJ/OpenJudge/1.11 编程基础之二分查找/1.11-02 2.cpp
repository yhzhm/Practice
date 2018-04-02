// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
double a;
double f(double x) {
	return pow(x, 5) - 15 * pow(x, 4) + 85 * pow(x, 3) - 225 * x * x + 274 * x - 121;
}
void bs(double l, double r)
{
	double mid = (l + r) / 2;
	if (r - l <= 0.0000001) {a = mid; return;}
	if (f(mid) < 0) bs(l, mid);
	else bs(mid, r);
}
int main()
{
	// printf("%.6f\n", bs(1.5, 2.4));
	bs(1.5, 2.4);
	printf("%.6f", a);
	return 0;
}