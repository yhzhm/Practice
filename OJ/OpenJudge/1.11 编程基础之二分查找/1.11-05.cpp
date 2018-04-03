#include <bits/stdc++.h>
using namespace std;
int n, f;
double a[10010];
const double PI = acos(-1.0); //π精度要求很高
bool check(double mid)
{
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i] / mid;
	}
	return sum >= f + 1;
}
int main()
{
	cin >> n >> f;
	int x;
	double l = 0.0, r = 0.0, mid;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		a[i] = x * x * PI;
		r = max(r, a[i]);
	}
	while (r - l > 1e-5) {
		mid = l + (r - l) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.3f\n", l);
	return 0;
}

