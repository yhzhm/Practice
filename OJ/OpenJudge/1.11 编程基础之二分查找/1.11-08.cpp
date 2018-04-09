// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x;
	cin >> n;
	set<int> s;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		s.insert(x);
	}
	for (auto i : s) {
		printf("%d ", i);
	}
	return 0;
}