// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	set< pair<int, string> > s;
	for (int i = 0; i < n; ++i) {
		int score; string name;
		cin >> score >> name;
		s.insert(pair<int, string>(score, name));
	}
	cout << s.rbegin()->second << endl;
	return 0;
}