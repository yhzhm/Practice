// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> a, b;
	int x;
	for (int i = 1; i <= 10; ++i) {
		cin >> x;
		if (x % 2) a.push_back(x);
		else b.push_back(x);
	}
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << ' ';
	}
	for (int i = 0; i < b.size(); ++i) {
		cout << b[i] << ' ';
	}
	cout << endl;
	return 0;
}