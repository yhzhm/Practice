// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	typedef pair<double, int> st;
	vector<st> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end(), greater<st>());
	cout << v[k - 1].second << ' ' << v[k - 1].first << endl;
	return 0;
}