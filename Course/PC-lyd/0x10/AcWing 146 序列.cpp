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
			sort(b, b + n);
			work();
		}
		for (int i = 0; i < n; ++i) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}