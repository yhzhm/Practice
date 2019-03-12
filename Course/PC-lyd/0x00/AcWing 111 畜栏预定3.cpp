// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 5e4 + 10;
typedef pair<int, int> pii;
pair<pii, int> cows[M];//<开始时间，结束时间>,牛编号
int n, id[M];//id[]下标表示牛编号，记录畜栏号

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cows[i].first.first >> cows[i].first.second;
		cows[i].second = i;
	}
	sort(cows, cows + n);
	priority_queue<pii, vector<pii>, greater<pii>> heap;//小根堆

	for (int i = 0; i < n; ++i) {//遍历每头牛
		auto cow = cows[i].first;
		pii stall;//stall畜栏
		if (heap.empty() || heap.top().first >= cow.first) {//堆为空或堆顶结束时间大于当前牛的开始时间，需新增畜栏
			stall = {cow.second, heap.size() + 1};//结束时间和畜栏编号
		} else {//否则，更新堆顶
			stall = heap.top();	heap.pop();
			stall.first = cow.second;
		}
		heap.push(stall);//入堆
		id[cows[i].second] = stall.second;//记录当前牛的畜栏号
	}

	cout << heap.size() << endl;//输出畜栏数量
	for (int i = 0; i < n; ++i) cout << id[i] << endl;//输出方案
	return 0;
}