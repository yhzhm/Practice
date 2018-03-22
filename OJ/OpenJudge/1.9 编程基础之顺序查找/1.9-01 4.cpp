// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x, t;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		v.push_back(t);
	}
	cin >> x;
	vector<int>::iterator p;
	p = find(begin(v), end(v), x);
	if (p != end(v)) cout << p - begin(v) + 1;
	else cout << -1;
	return 0;
}