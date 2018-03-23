// Created by Hz Yang on 2017.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[n - 1] - v[0] << endl;
	return 0;
}