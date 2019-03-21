// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
char s[M];
int nex[M], n, T;

void calc_next()
{
	nex[1] = 0;
	for (int i = 2, j = 0; i <= n; ++i) {
		while (j > 0 && s[i] != s[j + 1]) j = nex[j];
		if (s[i] == s[j + 1]) j++;
		nex[i] = j;
	}
}

int main()
{
	while (cin >> n && n)
	{
		scanf("%s", s + 1);
		calc_next();
		printf("Test case #%d\n", ++T);
		for (int i = 2; i <= n; ++i) {
			int len = i - nex[i];
			if (i % len == 0 && i / len > 1) printf("%d %d\n", i, i / len);
		}
		printf("\n");
	}
	return 0;
}