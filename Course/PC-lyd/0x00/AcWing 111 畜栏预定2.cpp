// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int MAX = 50010;
struct node
{
	int st, ed, id;//st开始时间，ed结束时间，id记录牛的初始编号
	bool operator < (const node &b) const {//重载<实现小根堆
		if (this->ed == b.ed)return this->st > b.st;
		return this->ed > b.ed;
	}
} a[MAX];
int b[MAX];//记录蓄栏编号
priority_queue<node> p;//结束时间早的在栈顶，代替数组轮询提高效率
bool cmp(node a, node b)//用于数组排序，根据开始时间从小到大排序
{
	if (a.st == b.st) return a.ed < b.ed;
	return a.st < b.st;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)	{
		cin >> a[i].st >> a[i].ed;
		a[i].id = i + 1;
	}
	sort(a, a + n, cmp);

	int ans = 0;
	for (int i = 0; i < n; ++i) {//遍历每头牛
		if (!p.empty() && p.top().ed < a[i].st) {//堆头元素可以被替换
			b[a[i].id] = b[p.top().id];//蓄栏编号和被替换的堆头元素一样
			p.pop();
		} else {//开新蓄栏
			ans++;
			b[a[i].id] = ans;
		}
		p.push(a[i]);//新牛入堆
	}
	cout << ans << endl;
	for (int i = 1; i <= n; ++i) cout << b[i] << endl;
	return 0;
}
/*
priority_queue代替数组轮询，从而将o(n^2)提高到o(nlogn)
优先队列默认的<，完成的是大根堆，通过自定义<实现小根堆
数组排序用自定义cmp实现根据开始时间从小到大排序
 */