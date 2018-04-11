// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
void change(string &s)
{
	for (int i = 0; i < s.size(); ++i) {
		if (isupper(s[i])) s[i] = tolower(s[i]);
	}
}
int main()
{
	string s, x;
	cin >> s;
	getline(cin, x);
	getline(cin, x);
	change(s); change(x);
	int first = -1, sum = 0, count, i, j;
	for (i = 0; i <= x.size() - s.size(); ++i) {
		count = 0;
		for (j = 0; j < s.size(); ++j) {
			if (x[i + j] == s[j]) count++;
			else break;
		}
		if (count == s.size() && x[i - 1] == ' ' && x[i + j] == ' ') {
			sum++;
			if (first == -1) first = i;
		}
	}
	if (sum) cout << sum << ' ' << first << endl;
	else cout << first << endl;
	return 0;
}