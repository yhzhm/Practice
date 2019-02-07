// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> path;
void dfs(int u, int state)
{
	if (u == n) {
		for (auto x : path) cout << x << ' ';
		cout << endl;
		return;
	}
	for (int i = 0; i < n; ++i) {//当前箱子，枚举每个数，找没用过的放入箱子
		if (!(state >> i & 1)) {
			path.push_back(i + 1);
			dfs(u + 1, state | 1 << i);
			path.pop_back();//要保证同一次（位置）枚举的时候，对于对于所有的分枝，在进入之前，所有状态都是一样的，所以要恢复状态
		}
	}
}
int main()
{
	cin >> n;
	dfs(0, 0);//(枚举到第几个箱子，用过哪些数)
	return 0;
}

/*
考虑按什么顺序枚举：
有n个数，n个箱子，从第一个箱子开始依次枚举每一个箱子
对每一个箱子，选择当前没有被选择过的数，直到将n个数放完为止（n个箱子放完为止）
就得到一个方案
因为方案有顺序，所以不能用二进制数表示，二进制数只能表示数有没有被用过，不能记录顺序

 */