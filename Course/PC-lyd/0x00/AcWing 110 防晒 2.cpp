// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int M = 2510;
int n, m;
pii cows[M];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> cows[i].first >> cows[i].second;
	sort(cows, cows + n);

	map<int, int> spfs;
	for (int i = 0; i < m; ++i) {
		int spf, cover;
		cin >> spf >> cover;
		spfs[spf] += cover;
	}

	int res = 0;
	spfs[0] = spfs[1001] = n;
	for (int i = n - 1; i >= 0; --i) {
		auto cow = cows[i];
		auto it = spfs.upper_bound(cow.second);
		it--;
		if (it->first >= cow.first && it->first <= cow.second) {
			res++;
			if (--it->second == 0) spfs.erase(it);
		}
	}

	cout << res << endl;
	return 0;
}