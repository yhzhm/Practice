// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
using namespace std;
int n, w, ans;
int c[20], cab[20];

void dfs(int now, int cnt)
{
	if (cnt >= ans) return;//cnt一旦大于等于ans，可以立即回溯
	if (now == n + 1) {ans = min(ans, cnt); return;} //边界，更新答案

	//最多有cnt + 1个分支，逐一尝试
	for (int i = 1; i <= cnt; ++i) //枚举现有cnt辆缆车，判断能否装下当前小猫
		if (cab[i] + c[now] <= w) {
			cab[i] += c[now];
			dfs(now + 1, cnt);
			cab[i] -= c[now];
		}

	cab[cnt + 1] = c[now];//新租缆车安置小猫
	dfs(now + 1, cnt + 1);
	cab[cnt + 1] = 0;
}

int main()
{
	cin >> n >> w;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	sort(c + 1, c + 1 + n, greater<int>());
	ans = n;
	dfs(1, 0);//第1只小猫，目前已用了0辆车

	cout << ans << endl;
	return 0;
}