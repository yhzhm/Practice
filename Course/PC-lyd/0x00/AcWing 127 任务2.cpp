// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
typedef pair<int, int> PII;
typedef long long LL;
int n, m;
PII mchs[M], tasks[M];

int main()
{
	while (cin >> n >> m) {
		for (int i = 0; i < n; ++i) cin >> mchs[i].first >> mchs[i].second;
		for (int i = 0; i < m; ++i) cin >> tasks[i].first >> tasks[i].second;
		sort(mchs, mchs + n); sort(tasks, tasks + m);

		multiset<int> ys;
		LL cnt = 0, res = 0;
		for (int i = m - 1, j = n - 1; i >= 0; --i) {
			int x = tasks[i].first, y = tasks[i].second;
			while (j >= 0 && mchs[j].first >= x) ys.insert(mchs[j--].second);
			auto it = ys.lower_bound(y);
			if (it != ys.end()) {
				cnt++;
				res += 500 * x + 2 * y;
				ys.erase(it);
			}
		}
		cout << cnt << ' ' << res << endl;
	}
	return 0;
}
/*
贪心
因为时间占比大，所以以时间为第一排序条件，机器级别为第二排序条件
 */