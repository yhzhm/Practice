// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	double a[n], sum = 0.0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	sum = sum - a[0] - a[n - 1];
	double avg = sum / (n - 2);
	double x = -1e10;;
	for (int i = 1; i < n - 1; ++i) {
		x = max(x, abs(a[i] - avg));
	}
	cout << setprecision(.2) << avg << ' ' << x << endl;
	return 0;
}