// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (a % 70 == 0) sum += a / 70;
		else sum += (a / 70) + 1;
	}
	printf("%.1f\n", (double)sum / 10);
	return 0;
}