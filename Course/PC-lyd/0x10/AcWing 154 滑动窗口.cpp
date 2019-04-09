// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int n, k, x;
queue<int> q;//保存读入序列
vector<int> minq, maxq;//记录最小值和最大值
map<int , int> mp;//map自动有序
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < k; ++i) scanf("%d", &x), mp[x]++, q.push(x);//读入前k-1个
	for (int i = k; i <= n; ++i) {//q满k个后开始处理
		scanf("%d", &x);
		mp[x]++; q.push(x);
		minq.push_back(mp.begin()->first); maxq.push_back((--mp.end())->first);//分别保存当前窗口的最大最小值
		x = q.front();//q中第一个元素出队列
		mp[x]--; q.pop();
		if (mp[x] == 0) mp.erase(x);//删除零值二元组
	}

	vector<int>::size_type i, endv;//AcWing上不考虑最后空格也AC
	for (i = 0, endv = minq.size() - 1; i < endv; ++i) printf("%d ", minq[i]); printf("%d\n", minq[endv]);
	for (i = 0, endv = maxq.size() - 1; i < endv; ++i) printf("%d ", maxq[i]); printf("%d\n", maxq[endv]);
	return 0;
}