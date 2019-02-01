// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int m, n;//m编号，n数字个数
		cin >> m >> n;
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int> > min_heap;

		printf("%d %d\n", m, (n + 1) / 2);//输出编号和奇数个数的中位数个数
		int cnt = 0;//统计输出个数，满10时换行
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if (!i) min_heap.push(x);//第1个数，直接加入小顶堆
			else {
				if (x < min_heap.top())	max_heap.push(x);//将x与边界（小顶堆的堆顶）比较，决定放入哪个堆
				else min_heap.push(x);
				//维持两个堆的数量，保证相等或小顶堆多1
				if (max_heap.size() > min_heap.size())
					min_heap.push(max_heap.top()), max_heap.pop();
				if (min_heap.size() > max_heap.size() + 1)
					max_heap.push(min_heap.top()), min_heap.pop();
			}

			if (!(i & 1)) { //第奇数个数，因为循环从0开始，所以这里是判断是偶数时输出
				printf("%d ", min_heap.top());//小顶堆顶即当前中位数
				if ( ++cnt % 10 == 0) puts("");//满10换行
			}
		}
		if (cnt % 10) puts("");//一组数据输出完毕，没有满10也要换行
	}
	return 0;
}

/*
维持分界点始终在小根堆顶，小根堆顶即所求中位数

 */