// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin >> k;
	string s;
	cin >> s;
	s = ' ' + s + ' ';
	int count = 1;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] != s[i - 1]) {
			if (count >= k) {cout << s[i - 1] << endl; return 0;}
			count = 1;
		} else count++;
	}
	cout << "No" << endl;
	return 0;
}