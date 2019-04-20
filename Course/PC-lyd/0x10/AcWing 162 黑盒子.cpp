// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n, x;
	cin >> m >> n;
	vector<int> num;
	for (int i = 1; i <= m; ++i) cin >> x, num.push_back(x);
	queue<int> q;
	for (int i = 1; i <= n; ++i) cin >> x, q.push(x);
	multiset<int> s;
	auto it = s.begin(); int j, p = 0;
	for (int i = 0; i < num.size(); ++i) {
		s.insert(num[i]);
		while (q.size() && q.front() == (i + 1) ) {
			for (it = s.begin(), j = 0; it != s.end(); ++it, ++j) {
				if (j == p) {cout << *it << endl; p++; break;}
			}
			q.pop();
		}
	}
	return 0;
}