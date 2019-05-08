// Created by Hz Yang on 2019.05
#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const int M = 100010;
int n, k, x;
int l[M], r[M];
LL d[M], v[M], sum, cnt;

void delete_node(int p)
{
	r[l[p]] = r[p];
	l[r[p]] = l[p];
}

int main()
{
	cin >> n >> k;
	int tot = 1;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (v[tot]*x >= 0) v[tot] += x;
		else v[++tot] = x;
	}
	int lp = 1;
	if (v[1] <= 0) lp++;
	if (v[tot] <= 0) tot--;

	set<PLI> s;
	for (int i = lp; i <= tot; ++i) {
		l[i] = i - 1;
		r[i] = i + 1;
		if (v[i] > 0) sum += v[i], cnt++;
		v[i] = abs(v[i]);
		s.insert({v[i], i});
	}
	l[lp] = r[tot] = 0;
	// cout << sum << endl << cnt << endl;
	while (cnt > k) {
		auto it = s.begin();
		LL u = it->first;
		int p = it->second;
		int left = l[p], right = r[p];

		// cout << cnt - k << ':' << sum << ' ' << u << endl;
		sum -= u;
		s.erase(it);

		if (left == 0) {
			s.erase({v[right], right});
			delete_node(right); delete_node(p);
		} else if (right == 0) {
			s.erase({v[left], left});
			delete_node(left); delete_node(p);
		} else {
			s.erase({v[left], left}), s.erase({v[right], right});
			delete_node(left), delete_node(right);
			v[p] = v[left] + v[right] - v[p];
			s.insert({v[p], p});
		}
		cnt--;
	}

	cout << sum << endl;
	return 0;
}
/*
方法1，用一个很大的值做哨兵，可以简化边界处理；
方法2，用链表下标值做哨兵，需要特判边界情况
 */