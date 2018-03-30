// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
struct st
{
	int score = 0;
	string name = "";
};
bool comp(st a, st b)
{
	return a.score > b.score;
}
int main()
{
	int n;
	cin >> n;
	st a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i].score >> a[i].name;
	}
	sort(a, a + n, comp);
	cout << a[0].name << endl;
	return 0;
}