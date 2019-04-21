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
		if (ed[p] == 1) return false;//若存在某个节点为1，则该字符串并非某个字符串的子串
	}
	return true;//遍历字符串s的所有字符，每个字符出现次数都大于1，说明s是某个字符串的子串
}

// void out()
// {
// 	for (int  i = 0; i < 10; ++i) {
// 		for (int j = 0; j < 10; ++j) {
// 			cout << trie[i][j] << ' ';
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// 	for (int i = 0; i < 10; ++i) cout << ed[i] << ' ';
// 	cout << endl;
// 	cout << endl;
// }

int main()
{
	cin >> T;
	while (T --) {
		init();
		cin >> n;
		for (int i = 1; i <= n; ++i) scanf("%s", s[i]), insert(s[i]);
		int ok = 1;
		for (int i = 1; i <= n; ++i) {
			// cout << i << ':' << find(s[i]) << endl;
			if (find(s[i])) {ok = 0; break;}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}