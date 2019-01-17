// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	typedef pair<int, string> st;
	set<st> s; st z;
	for (int i = 0; i < n; ++i) {
		cin >> z.first >> z.second;
		s.insert(z);
	}
	set<st>::iterator p;
	p = s.end();
	// p--;
	cout << (--p)->second << endl;
	return 0;
}