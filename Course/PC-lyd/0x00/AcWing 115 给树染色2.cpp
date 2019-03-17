// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 10;
int n, root;
struct Node
{
	int father, size, sum;//father:父节点，size：当前子树中节点的个数，sum：当前子树中所有节点的权值和
	double avg;//当前子树中所有节点的平均值
} nodes[M];

int find()//找当前权值最大的非根节点
{
	double avg = 0; int res = -1;
	for (int i = 1; i <= n; ++i)
		if (i != root && avg < nodes[i].avg) {
			avg = nodes[i].avg;
			res = i;
		}
	return res;
}
int main()
{
	int res = 0;
	cin >> n >> root;
	for (int i = 1; i <= n; ++i) {
		auto &nd = nodes[i];//用一个较短的变量存储当前变量
		cin >> nd.sum;
		nd.size = 1;
		nd.avg = nd.sum;
		res += nd.sum;
	}
	for (int i = 0, a, b; i < n - 1; ++i) { //读入n-1对关系
		cin >> a >> b;
		nodes[b].father = a;
	}
	for (int i = 0; i < n - 1; ++i) {//合并n-1次
		int ver = find();//找当前权值最大的非根节点
		int f = nodes[ver].father;
		res += nodes[ver].sum * nodes[f].size;//累加代价
		nodes[ver].avg = -1;//将最大节点的等效权值置为-1,不再能被find搜索到，相当于删除了该节点
		for (int j = 1; j <= n; ++j)//枚举所有点，符合条件的合并
			if (nodes[j].father == ver) nodes[j].father = f;
		nodes[f].sum += nodes[ver].sum;//更新当前节点的父节点信息
		nodes[f].size += nodes[ver].size;
		nodes[f].avg = (double)nodes[f].sum / nodes[f].size;
	}
	cout << res << endl;
	return 0;
}

/*
acwing上的测试数据不是多组，只有一组
方法和1一样，变量的命名更有意义

 */