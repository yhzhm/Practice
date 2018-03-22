// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> st;
int main()
{
	int n;
	cin >> n;
	vector<st> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), greater<st>());
	cout << v[0].second << endl;
	return 0;
}