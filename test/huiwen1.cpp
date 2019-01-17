// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
bool check(int n)
{
	int s = 0;
	int x = n;
	while (n) {
		s = s * 10 + n % 10;
		n /= 10;
	}
	return s == x;
}
bool isp(int n)
{
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}
int main()
{
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		if (check(i) && isp(i)) sum++;
	}
	cout << sum << endl;
	return 0;
}