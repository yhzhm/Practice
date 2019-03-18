// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int main()
{
	string s;
	int T;
	cin >> s >> T;
	while (T--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		string s1 = s.substr(l1 - 1, r1 - l1 + 1);
		string s2 = s.substr(l2 - 1, r2 - l2 + 1);
		// cout << ( (s1 == s2) ? "Yes" : "No" ) << endl;
		if (s1 == s2) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}