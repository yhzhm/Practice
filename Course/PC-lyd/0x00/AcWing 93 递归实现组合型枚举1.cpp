// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
int n, m;
void dfs(int u, int sum, int state) {
	if (sum + n - u < m) return;//把剩下的数都选上也不够m个数
	if (sum == m) {
		for (int i = 0; i < n; ++i) {
			if (state >> i & 1) {
				cout << i + 1 << ' ';
			}
		}
		cout << endl;
		return;
	}

	dfs(u + 1, sum + 1, state + (1 << u));//因为要字典序排列，所以先“选”
	dfs(u + 1, sum, state);
}
int main()
{
	cin >> n >> m;
	dfs(0, 0, 0);//(枚举到第几个数，当前已经选了多少个数，选了哪些数) 用整数的位表示集合，表示选了哪些数，也就是方案
	return 0;
}