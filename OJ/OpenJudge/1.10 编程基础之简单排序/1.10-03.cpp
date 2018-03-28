// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
struct st
{
	string name;
	int score;
};
bool comp(st a, st b)
{
	return (a.score > b.score) || (a.score == b.score && a.name < b.name) ;
}
int main()
{
	int n;
	cin >> n ;
	st s[n];
	for (int i = 0; i < n; ++i) {
		cin >> s[i].name >> s[i].score;
	}
	sort(s, s + n, comp);
	for (int i = 0; i < n; ++i) {
		cout << s[i].name << ' ' << s[i].score << endl;
		// printf("%s %d\n", s[i].name.c_str(), s[i].score); //c_str()不推荐使用
	}
	return 0;
}