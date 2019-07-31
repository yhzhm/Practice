// Created by Hz Yang on 2019.06
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> PIIi;
const int N = 100;
PIIi a[N];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i].first.second >> a[i].first.first, a[i].second = i + 1;
	sort(a, a + n);
	for (int i = 0; i < n; ++i) cout << a[i].first.second << ' ' << a[i].first.first << ':' << a[i].second << endl;
	int sum = a[0].first.first - a[0].first.second + 1;
	vector<int> res; res.push_back(a[0].second);
	for (int i = 1, j = 0; i < n; ++i) {
		if (a[i].first.second > a[j].first.first) {
			j = i;
			sum += a[i].first.first - a[i].first.second + 1;
			res.push_back(a[i].second);
		}
	}
	cout << sum << endl;
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i) cout << res[i] << ' ';
	cout << endl;
	return 0;
}