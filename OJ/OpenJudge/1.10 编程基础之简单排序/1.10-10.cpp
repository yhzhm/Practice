// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	set<string> s;
	string x;
	while (cin >> x) {
		s.insert(x);
	}
	set<string>::iterator i;
	for (i = s.begin(); i != s.end(); ++i) {
		cout << *i << endl;
	}
	return 0;
}