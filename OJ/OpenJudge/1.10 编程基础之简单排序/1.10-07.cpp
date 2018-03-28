// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<double> a, b;
	int n; string x; double h;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> h;
		if (x == "male") a.push_back(h);
		else b.push_back(h);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<double>());
	for (int i = 0; i < a.size(); ++i) {
		printf("%.2f ", a[i]);
	}
	for (int i = 0; i < b.size(); ++i) {
		printf("%.2f ", b[i]);
	}
	cout << endl;
	return 0;
}