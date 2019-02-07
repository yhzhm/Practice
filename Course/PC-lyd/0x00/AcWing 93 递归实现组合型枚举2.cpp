// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
int n, m;
void dfs(int u, int sum, int state) {
	if (sum + n - u < m) return;
	if (sum == m) {
		for (int i = 0; i < n; ++i) {
			if (state >> i & 1) {
				cout << i + 1 << ' ';
			}
		}
		cout << endl;
		return;
	}

	for (int i = u; i < n; ++i) {
		dfs(i + 1, sum + 1, state + (1 << i));//等价于：state | 1 << u
	}
}
int main()
{
	cin >> n >> m;
	dfs(0, 0, 0);
	return 0;
}