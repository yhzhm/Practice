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
			if (!i) min_heap.push(x);
			else {//判断应该加入哪个堆，堆size变化时，判断是否需要对两堆数量进行调整
				if (x < min_heap.top()) {
					max_heap.push(x);
					if (max_heap.size() > min_heap.size())
						min_heap.push(max_heap.top()), max_heap.pop();
				}
				else {
					min_heap.push(x);
					if (min_heap.size() > max_heap.size() + 1)
						max_heap.push(min_heap.top()), min_heap.pop();
				}
			}


			if (!(i & 1)) { //第奇数个数，因为循环从0开始，所以这里是判断第偶数个数
				printf("%d ", min_heap.top());
				if ( ++cnt % 10 == 0) puts("");
			}
		}
		if (cnt % 10) puts("");
	}
	return 0;
}

/*
维持分界点始终在小根堆顶，小根堆顶即所求中位数

 */