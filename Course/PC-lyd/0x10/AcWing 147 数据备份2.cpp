// Created by Hz Yang on 2019.05
#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const int M = 100010;
int n, k;
int l[M], r[M];
LL d[M];

void delete_node(int p)
{
	r[l[p]] = r[p];
	l[r[p]] = l[p];
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> d[i];
	for (int i = n - 1; ~i; --i) d[i] -= d[i - 1];

	set<PLI> s;
	d[0] = d[n] = 1e15;
	for (int i = 0; i <= n; ++i) {
		l[i] = i - 1;
		r[i] = i + 1;
		if (i >= 1 && i < n) s.insert({d[i], i});
	}

	LL res = 0;
	while (k --) {
		auto it = s.begin();
		LL v = it->first;
		int p = it->second;
		int left = l[p], right = r[p];

		s.erase(it);
		s.erase({d[left], left}), s.erase({d[right], right} );
		delete_node(left), delete_node(right);
		res += v;

		d[p] = d[left] + d[right] - d[p];
		s.insert({d[p], p});
	}

	cout << res << endl;
	return 0;
}