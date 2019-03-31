// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
typedef long long  ll;
typedef pair<ll, ll> PLL;//权值，深度
ll ans, n, k, x;
priority_queue<PLL, vector<PLL>, greater<PLL> > pq;//小根堆,权值小的k个节点先合并

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {//读取节点权值（单词出现次数）并入堆
		scanf("%lld", &x);
		pq.push({x, 0});
	}
	while ((pq.size() - 1) % (k - 1)) pq.push({0, 0});//补充0节点，满足K叉哈夫曼树
	while (pq.size() >= k) {
		ll deep = -1, temp = 0;
		for (int j = 1; j <= k; ++j) {//k个节点合并成1个节点
			auto dx = pq.top(); pq.pop();//取出堆顶节点
			temp += dx.first;//累加k个点的权值，作为新节点的权值
			deep = max(deep, dx.second);//这里深度值上大下小，所以用max取深度小的
		}
		pq.push({temp, deep + 1});
		ans += temp;
	}
	cout << ans << endl << pq.top().second << endl;
	return 0;
}