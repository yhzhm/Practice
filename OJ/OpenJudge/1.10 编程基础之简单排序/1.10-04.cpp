// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
struct st
{
	int no, y, s, w, t;
};
bool comp(st a, st b)
{
	if (a.t > b.t) return true;
	else if (a.t == b.t && a.y > b.y) return true;
	else if (a.t == b.t && a.y == b.y) return a.no < b.no;
	else return false;
}
int main()
{
	int n;
	cin >> n;
	st s[n];
	for (int i = 0; i < n; ++i) {
		s[i].no = i + 1;
		cin >> s[i].y >> s[i].s >> s[i].w;
		s[i].t = s[i].y + s[i].s + s[i].w;
	}
	sort(s, s + n, comp);
	for (int i = 0; i < 5; ++i) {
		cout << s[i].no << ' ' << s[i].t << endl;
	}
	return 0;
}