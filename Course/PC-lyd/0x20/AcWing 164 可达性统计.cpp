// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;
const int M = 30010;
int n, m, deg[M], a[M];//deg[]:节点深度 a[]:记录拓扑排序结果
int ver[M], head[M], Next[M], tot, cnt;//ver[]:边的终点 head[]:表头 Next[]:之前的一条边
bitset<M> f[M];

void add(int u, int v)//将有向边(u,v)加入邻接表
{
	ver[++tot] = v, Next[tot] = head[u], head[u] = tot;
	deg[v]++;
}

int main()
{
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	//拓扑排序
	queue<int> q;
	for (int i = 1; i <= n; ++i) if (deg[i] == 0) q.push(i);//将所有入度为0的节点加入队列
	while (q.size()) {
		int x = q.front(); q.pop();
		a[++cnt] = x;//加入拓扑排序序列
		for (int i = head[x]; i; i = Next[i]) {//遍历从x出发的边
			int y = ver[i];
			if (--deg[y] == 0) q.push(y);//如果删除x点后，该边终点入度为0，将该终点加入队列
		}
	}

	for (int i = cnt; i; --i) {//根据拓扑排序序列，从后往前计算
		int x = a[i];
		f[x][x] = 1;//点x的第x位设为1
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			f[x] |= f[y];//对后继节点y的f值求并
		}
	}

	for (int i = 1; i <= n; ++i) printf("%d\n", f[i].count());//输出f[i]中1的个数，即答案

	return 0;
}

/*
从x出发能够到达的点，是从“x的各个后继节点y”出发能够到达的点的并集，再加上点x自身。
所以，在计算出一个点的所有后继节点的f值之后，就可以计算出该点的f值。
这启发我们先用拓扑排序算法求出一个拓扑序，然后按照拓扑序的倒序进行计算。
因为在拓扑排序中，对任意的一条边(x,y),x都排在y之前。

二进制状态压缩，用一个n位二进制数存储每个f(x),二进制数的第i位是1表示x能到i。
对若干个集合求并，就相当于对若干个n位二进制做“按位或”运算。
最后，每个f(x)中1的个数就是从x出发能够到达的节点数量。
 */