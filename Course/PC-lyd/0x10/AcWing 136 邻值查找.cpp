// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
int h[M], g[3], n, m, p;//h[]存输入数据,g[]存邻值
struct rec {int x, y;};//x:编号i，y:数值
set<rec> s;//用set排序
set<rec>::iterator it, lt, rt;//迭代器变量
bool operator <(rec a, rec b)//set元素必须能比较大小
{
	return a.y < b.y;
}
bool cmp(int a, int b, int i)//比较前驱、后继与h[i]的差
{
	//若相同，返回值较小的那个
	return abs(h[a] - h[i]) < abs(h[b] - h[i]) ||
	       (abs(h[a] - h[i]) == abs(h[b] - h[i]) && h[a] < h[b]);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
	for (int i = 1; i <= n; ++i) {
		rec now; now.x = i, now.y = h[i];
		s.insert(now);
		it = s.find(now);

		lt = rt = it, m = 0;
		if (lt != s.begin()) lt--, g[++m] = lt->x;//前驱
		if (rt++, rt != s.end()) g[++m] = rt->x;//后继，注意先rt++

		if (i >= 2) {//根据题意，从h[2]开始
			if (m < 2 || cmp(g[1], g[2], i)) p = g[1];//m<2,上面两个if语句只执行了一次，故只有g[1]有值，
			else p = g[2];
			printf("%d %d\n", abs(h[i] - h[p]), p);
		}
	}
	return 0;
}
/*
h[1],h[2],...,h[n]依次插入一个集合，则在插入h[i]之前，集合中保存的就是满足1<=j<i的所有h[j]。
根据题意，我们只需在集合中查找与h[i]最接近的值。
set是平衡二叉树，能保证数据有序，所以与h[i]最接近的值，要么是h[i]的前驱，要么是h[i]的后继，
比较前驱、后继与h[i]的差即可。


 */