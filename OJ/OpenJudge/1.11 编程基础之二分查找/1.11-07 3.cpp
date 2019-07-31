// Created by Hz Yang on 2019.06
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
int n, m, a[M];
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] <= m / 2) {
			int l = i + 1, r = n;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (a[mid] + a[i] >= m) r = mid;
				else l = mid + 1;
			}
			if (a[l] == m - a[i]) {
				cout << a[i] << ' ' << a[l] << endl;
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}