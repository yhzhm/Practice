// Created by Hz Yang on 2019.04
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int M = 1e5 + 10;

int n;
int h[M], q[M], Left[M], Right[M];

void get(int bound[M])
{
	h[0] = -1;
	int tt = 0;
	for (int i = 1; i <= n; ++i) {
		while (h[q[tt]] >= h[i]) tt--; //栈顶元素大于等于当前元素，出栈
		bound[i] = q[tt]; //剩下的栈顶元素，就是左边第一个比当前元素小的元素
		q[++tt] = i; //当前元素入栈
	}

}

int main()
{
	while (cin >> n, n) {
		for (int i = 1; i <= n; ++i) cin >> h[i];

		get(Left);
		reverse(h + 1, h + n + 1);
		get(Right);

		LL res = 0;
		for (int i = 1, j = n; i <= n; ++i, --j)
			res = max(res, h[i] * (n + 1 - Left[j] - Right[i] - 1ll));

		cout << res << endl;
	}
	return 0;
}