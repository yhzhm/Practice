// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string name;
	double t;
	bool x;
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> name >> t >> x;
		if (t >= 37.5 && x) {
			cout << name << endl;
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}