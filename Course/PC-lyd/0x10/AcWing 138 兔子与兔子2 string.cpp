// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
unsigned long long f[M], p[M];
int main()
{
	string s; int T;
	cin >> s >> T;
	p[0] = 1; s = ' ' + s;
	for (int i = 1; i < s.size(); ++i) {
		f[i] = f[i - 1] * 131 + (s[i] - 'a' + 1);
		p[i] = p[i - 1] * 131;
	}
	while (T--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (f[r1] - f[l1 - 1]*p[r1 - l1 + 1] == f[r2] - f[l2 - 1]*p[r2 - l2 + 1])
			puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
120ms

 */