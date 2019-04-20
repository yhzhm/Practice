// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int trie[M][10], ed[M], T, n, tot;
char s[M][10];

void init()
{
	tot = 1;
	memset(trie, 0, sizeof trie);
	memset(ed, 0, sizeof ed);
}

void insert(char* s)
{
	int len = strlen(s), p = 0;
	for (int i = 0; i < len; ++i) {
		int c = s[i] - '0';
		if (trie[p][c] == 0) trie[p][c] = tot++;
		p = trie[p][c];
		ed[p]++;
	}
}

bool find(char* s)
{
	int len = strlen(s), p = 0;
	for (int i = 0; i < len; ++i) {
		int c = s[i] - '0';
		p = trie[p][c];
		if (ed[p] == 1) return false;
	}
	return true;
}

int main()
{
	cin >> T;
	while (T --) {
		init();
		cin >> n;
		for (int i = 1; i <= n; ++i) scanf("%s", s[i]), insert(s[i]);
		int ok = 1;
		for (int i = 1; i <= n; ++i)
			if (find(s[i])) {ok = 0; break;}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}