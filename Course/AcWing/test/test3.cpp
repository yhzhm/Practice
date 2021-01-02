// Created by Hz Yang on 2019.06
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
struct node
{
	int s, e, id;
} a[N];

bool cmp(const node a, const node b)
{
	if (a.e == b.e) return a.s < b.s;
	return a.e < b.e;
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i].s >> a[i].e, a[i].id = i + 1;
	sort (a, a + n, cmp);
	int sum = a[0].e - a[0].s + 1;
	vector<int> res; res.push_back(a[0].id);
	for (int i = 1, j = 0; i < n; ++i) {
		if (a[i].s >= a[j].e) {
			j = i;
			sum += a[i].e - a[i].s + 1;
			res.push_back(a[i].id);
		}
	}
	cout << sum << endl;
	sort (res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i) cout << res[i] << ' ';
	cout << endl;
	return 0;
}