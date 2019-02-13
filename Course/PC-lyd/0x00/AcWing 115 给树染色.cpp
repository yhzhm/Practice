// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
int n, r, ans;
struct node
{
	int t, p, c; //t用于计算第几次染色，p当前节点的父节点，c节点权值
	double w;//等效权值
} num[1010];

int find()//查找树中等效权值最大的节点，返回节点编号
{
	double maxr = 0; int res;
	for (int i = 1; i <= n; ++i) {
		if (i != r && num[i].w > maxr) {
			maxr = num[i].w;
			res = i;
		}
	}
	return res;
}

int main()
{
	while (cin >> n >> r && (n || r)) {//要注意数据最后没有0 0的情况
		ans = 0;
		for (int i = 1; i <= n; ++i) {//读入节点权值
			cin >> num[i].c;
			num[i].w = num[i].c;
			num[i].t = 1;
			ans += num[i].c;
		}
		for (int i = 1, a, b; i < n; ++i) {//读入、保存父子关系
			cin >> a >> b;
			num[b].p = a;
		}
		for (int i = 1; i < n; ++i) {//操作n-1次
			int pos = find();//pos等效权值最大节点的编号
			cout << pos << ' ';
			num[pos].w = 0;//将最大节点的等效权值置为0
			int f = num[pos].p;
			ans += num[pos].c * num[f].t;//染色并累加代价
			for (int j = 1; j <= n; ++j) {
				if (num[j].p == pos) num[j].p = f;//更新pos之子节点的父节点信息
			}
			num[f].c += num[pos].c;//累加节点权值，用于计算等效权值
			num[f].t += num[pos].t;//累加次数
			num[f].w = (double)num[f].c / num[f].t;//更新f之等效权值
		}
		cout << ans << endl;
	}
	return 0;
}

/*
等效权值=该点包含的原始权值总和÷该点包含的原始点数

 */