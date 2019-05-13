// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100], v[100], n, len, cnt;

// 正在拼第stick根原始木棒（已经拼好了stick-1根）
// 第stick根木棒的当前长度为cab
// 拼接到第stick根木棒中的上一根小木棍为last
bool dfs(int stick, int cab, int last)
{
	if (stick > cnt) return true; // 所有原始木棒已经全部拼好，搜索成功
	if (cab == len) return dfs(stick + 1, 0, 1); // 第stick根木棒已经拼好，去拼下一根
	int fail = 0;// 剪枝(2)
	for (int i = last; i <= n; ++i) { // 剪枝(1)：小木棍长度递减（从last开始枚举）
		if (!v[i] && cab + a[i] <= len && fail != a[i]) {
			v[i] = 1;
			if (dfs(stick, cab + a[i], i + 1)) return true;
			fail = a[i];
			v[i] = 0; // 还原
			if (cab == 0 || cab + a[i] == len) return false; // 20行dfs(stick, cab + a[i], i + 1)失败，剪枝(3,4)
			//剪枝3：“空木棒中尝试插入第一根木棍”的递归分支失败，直接判定当前分支失败
			//剪枝4：恰好拼接完整后，“接下来拼接剩余原始木棍”的递归分支失败，直接判定当前分支失败
		}
	}
	return false;
}

int main()
{
	while (cin >> n, n) {
		int sum = 0, val = 0, p = 0, x;
		for (int i = 1; i <= n; ++i) {
			cin >> x;
			if (x <= 50) {
				a[++p] = x;
				sum += x;
				val = max(val, x);
			}
		}
		n = p;
		sort(a + 1, a + 1 + n, greater<int>());
		for (len = val; len <= sum; len++) {
			if (sum % len) continue;
			cnt = sum / len;
			memset(v, 0, sizeof v);
			if (dfs(1, 0, 1)) break;
		}
		cout << len << endl;
	}

	return 0;
}