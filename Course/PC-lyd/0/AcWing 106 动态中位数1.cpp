// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int m, n;
		cin >> m >> n;
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int> > min_heap;

		printf("%d %d\n", m, (n + 1) / 2);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			max_heap.push(x);//新数直接加入大顶堆
			//根据大小判断是否需要交换堆顶，保证有序数列中，前一半在大根堆，后一半在小根堆
			if (min_heap.size() && min_heap.top() < max_heap.top()) {
				max_heap.push(min_heap.top()), min_heap.pop();
				min_heap.push(max_heap.top()), max_heap.pop();
			}
			//判断size是否需要维护，保证两堆size相等或大根堆比小根堆多1
			if (max_heap.size() > min_heap.size() + 1) {
				min_heap.push(max_heap.top()), max_heap.pop();
			}

			if (!(i & 1)) { //第奇数个数，因为循环从0开始，所以这里是判断第偶数个数
				printf("%d ", max_heap.top());
				if ( ++cnt % 10 == 0) puts("");
			}
		}
		if (cnt % 10) puts("");
	}
	return 0;
}

/*
维持分界点始终在大根堆顶，大根堆顶即所求中位数

 */