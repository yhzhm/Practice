// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 2010;
typedef pair<int, int> PII;
int a[M], b[M], c[M], n, m;

void work()
{
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	for (int i = 0; i < n; ++i) heap.push({a[0] + b[i], 0});

	for (int i = 0; i < n; ++i) {
		auto t = heap.top();
		heap.pop();
		c[i] = t.first;
		heap.push({t.first + a[t.second + 1] - a[t.second], t.second + 1});
	}

	memcpy(a, c, 4 * n);
}

int main()
{
	int T; cin >> T;
	while (T --) {
		cin >> m >> n;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n; ++j) scanf("%d", &b[j]);
			// sort(b, b + n); //b数组是否有序不影响结果
			work();//利用堆进行n路归并
		}
		for (int i = 0; i < n; ++i) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}

/*
考虑当m=2时的情况：
分组：
a0+b0 a1+b0 a2+b0 ... an+b0
a0+b1 a1+b1 a2+b1 ... an+b1
a0+b2 a1+b2 a2+b2 ... an+b2
.
.
.
a0+bn a1+bn a2+bn ... an+bn
在该分组方案中，每行最小值为每行队首，
现将n个队首入堆，然后取出堆顶（最小值），替换该队列中的下一个元素入堆
 */