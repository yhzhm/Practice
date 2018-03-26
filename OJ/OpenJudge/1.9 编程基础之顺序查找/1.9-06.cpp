// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
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
	string s;
	cin >> s;
	int maxn = 0, minn = 101;
	int a[128] = {0};
	for (int i = 0; i < s.size(); ++i) {
		a[(int)s[i]]++;
	}
	for (int i = 97; i <= 122; ++i) {
		maxn = max(maxn, a[i]);
		if (a[i]) minn = min(minn, a[i]);
	}
	if (isp(maxn - minn)) cout << "Lucky Word\n" << maxn - minn << endl;
	else cout << "No Answer\n" << 0 << endl;
	return 0;
}