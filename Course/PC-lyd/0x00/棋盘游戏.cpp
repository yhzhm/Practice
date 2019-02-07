// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
int st, en;//用整数st表示起始状态，用en表示目标状态
bool vis[1 << 16];//表示状态的整数作为hash表下标
queue< pp > q;
int main()
{
	int a;
	//读入输入数据，每次读1位，转化为整数
	for (int i = 0; i < 16; ++i) scanf("%1d", &a), st |= a << i;
	for (int i = 0; i < 16; ++i) scanf("%1d", &a), en |= a << i;
	vis[st] = 1;
	q.push(make_pair(0, st));
	while (!q.empty()) {
		pp now = q.front();
		q.pop();
		int step = now.first, x = now.second;
		if (x == en) {
			cout << step << endl;
			return 0;
		}
		for (int i = 0; i < 16; ++i) {
			int v, l, r;
			//左右交换，用异或运算做01互换，v为左右互换后的状态，l，r表示交换的两个数
			v = x ^ (1 << i) ^ (1 << (i + 1)), l = x & (1 << i), r = x & (1 << (i + 1));
			//互换数对中的l为每行的前3个数 且 v状态没出现过 且 l和r不同
			if ((i + 1) % 4 && !vis[v] && l ^ r)
				vis[v] = 1, q.push(make_pair(step + 1, v));
			//上下换
			if (i > 11) continue;//互换数对中的l在上3行
			v = x ^ (1 << i) ^ (1 << (i + 4)), l = x & (1 << i), r = x & (1 << (i + 4));
			if (!vis[v] && l ^ r)
				vis[v] = 1, q.push(make_pair(step + 1, v));
		}
	}
	return 0;
}