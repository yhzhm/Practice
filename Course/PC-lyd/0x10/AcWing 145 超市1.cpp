// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 10;
typedef pair<int, int> PII;
int main()
{
	int n;
	while (cin >> n) {
		vector<PII> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i].second >> v[i].first;
		sort(v.begin(), v.end());
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 0; i < n; ++i) {
			if (q.empty()) q.push(v[i].second);
			else if (v[i].first > q.size()) q.push(v[i].second);
			else if (v[i].second > q.top()) {
				q.pop();
				q.push(v[i].second);
			}
		}
		long long res = 0;
		while (!q.empty()) {
			res += q.top();
			q.pop();
		}
		cout << res << endl;
	}
	return 0;
}