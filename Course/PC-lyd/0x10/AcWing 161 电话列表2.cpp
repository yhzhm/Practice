// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 1e5 + 10;

int n;
int son[M][10], idx;
bool f[M];

bool insert(char *str)
{
	int p = 0;
	bool has_new = false;
	bool has_found = false;
	for (int i = 0; str[i]; ++i) {
		int u = str[i] - '0';
		if (!son[p][u]) {
			son[p][u] = ++idx;
			has_new = true;
		}
		p = son[p][u];
		if (f[p]) has_found = true;
	}
	f[p] = true;

	return has_new && !has_found;
}

int main()
{
	int t; cin >> t;
	while (t--) {
		cin >> n;
		memset(son, 0, sizeof son);
		memset(f, false, sizeof f);
		idx = 0;
		bool res = true;

		char str[20];
		for (int i = 0; i < n; ++i) {
			cin >> str;
			if (!insert(str)) res = false;
		}

		if (res) puts("YES");
		else puts("NO");
	}
	return 0;
}