// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
struct st
{
	int no, score;
};
bool comp(st a, st b)
{
	return (a.score > b.score) || (a.score == b.score && a.no < b.no);
}
int main()
{
	int n, m;
	cin >> n >> m;
	st s[n]; m = m * 1.5;
	cout << m << endl;
	for (int i = 0; i < n; ++i) {
		cin >> s[i].no >> s[i].score;
	}
	sort(s, s + n, comp);
	for (int i = m; i < n; ++i) {
		if (s[i].score == s[i - 1].score) m++;
		else break;
	}
	cout << s[m - 1].score << ' ' << m << endl;
	for (int i = 0; i < m; ++i) {
		cout << s[i].no << ' ' << s[i].score << endl;
	}
	return 0;
}