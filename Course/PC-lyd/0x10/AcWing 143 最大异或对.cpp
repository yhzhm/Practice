// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
int trie[M * 32][2], tot = 1, n, res;

void insert(int n)
{
	int p = 1;
	for (int k = 30; k >= 0; --k) {
		int ch = n >> k & 1;
		if (trie[p][ch] == 0) trie[p][ch] = ++tot;
		p = trie[p][ch];
	}
}

int search(int n)
{
	int p = 1, res = 0;
	for (int k = 30; k >= 0; --k) {
		int ch = n >> k & 1;
		if (trie[p][ch ^ 1]) {
			p = trie[p][ch ^ 1];
			res |= 1 << k;
		} else p = trie[p][ch];
	}
	return res;
}

int main()
{
	cin >> n; int x;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		insert(x);
		res = max(res, search(x));
	}
	cout << res << endl;
	return 0;
}