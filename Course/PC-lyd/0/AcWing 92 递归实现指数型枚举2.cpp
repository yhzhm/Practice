// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(int u, int state) {
	if (u == n) {
		for (int i = 0; i < n; ++i)
			if (state >> i & 1 ) cout << i + 1 << ' ';
		cout << endl;
		return;
	}
	dfs(u + 1, state);
	dfs(u + 1, state | 1 << u);//等价于：state + (1 << u)
}
int main()
{
	cin >> n;
	dfs(0, 0);//(从0开始，方案状态)方案状态可以用数组记录，也可以用整数的二进制形式记录
	return 0;
}

/*
数据范围是1~15，所以可以用2^n的算法来做
2^15==32768
思路：按什么样的顺序去递归枚举
本题可以从前往后枚举每一个数，每个数都有选和不选两个分支，
--叶节点就是方案？  叶节点数就是方案数
 */