// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int M = 100010;

int n, l[M], r[M], p[M];
PII a[M], ans[M];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + 1 + n);

	a[0].first = 1e9, a[n + 1].first = -1e9;
	for (int i = 1; i <= n; ++i) {
		l[i] = i - 1, r[i] = i + 1;
		p[a[i].second] = i;
	}

	for (int i = n; i > 1; --i) {
		int j = p[i], left = l[j], right = r[j];
		int vl = abs(a[j].first - a[left].first);
		int vr = abs(a[j].first - a[right].first);
		if (vl <= vr) ans[i] = {vl, a[left].second};
		else ans[i] = {vr, a[right].second};
		l[right] = left, r[left] = right;
	}

	for (int i = 2; i <= n; ++i) cout << ans[i].first << ' ' << ans[i].second << endl;

	return 0;
}