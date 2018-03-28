// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
struct st
{
	int num;
	double score;
};
bool comp(st a, st b)
{
	return a.score > b.score;
}
int main()
{
	int n, k;
	cin >> n >> k;
	st s[n];
	for (int i = 0; i < n; ++i) {
		cin >> s[i].num >> s[i].score;
	}
	sort(s, s + n, comp);
	k--;
	// cout << s[k].num << ' ' << s[k].score << endl;
	printf("%d %g", s[k].num, s[k].score);
	return 0;
}