// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int M = 2510;
int n, m;
pii cows[M];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> cows[i].first >> cows[i].second;
	sort(cows, cows + n);

	map<int, int> spfs;
	for (int i = 0; i < m; ++i) {
		int spf, cover;
		cin >> spf >> cover;
		spfs[spf] += cover;//累加（给出的spf值有可能重复）统计防晒值为spf的防晒霜的cover值
	}

	int res = 0;
	spfs[0] = spfs[1001] = n;//为了方便用平衡树处理最大最小问题，一般加最大最小两个哨兵
	for (int i = n - 1; i >= 0; --i) {
		auto cow = cows[i];
		auto it = spfs.upper_bound(cow.second);
		it--;
		if (it->first >= cow.first && it->first <= cow.second) {
			res++;
			if (--it->second == 0) spfs.erase(it);
		}
	}

	cout << res << endl;
	return 0;
}

/*
二分图 匈牙利算法
当前匹配是最大匹配的充要条件是该匹配不存在增广路径

证明该贪心算法正确性：
如果通过这个贪心算法得到的匹配（线段（防晒范围）和点（防晒霜的值）的匹配）不存在一个增广路径，则该贪心算法是正确的

*/

/*
算法流程：

将所有奶牛按照 minSPF 从大到小的顺序排序，然后依次考虑每头奶牛；
对于每头奶牛，扫描当前所有能用的防晒霜，选择 SPF 值最大的防晒霜来用；

证明：
将所有奶牛和防晒霜分别看成两个集合中的点，如果一头奶牛可以使用某个防晒霜，则在两个点之间连一条边，那么问题就变成二分图求最大匹配了；
根据匈牙利算法的原理，如果一个匹配不存在增广路径，则该匹配是二分图的一个最大匹配。下面我们来证明按照上述做法得到的匹配方案，不存在增广路径。
反证，假设存在增广路径，我们来看其中最短的一条。为了方便，我们用 ci 表示第 i 头牛，用 si 表示第 i 个防晒霜。
假设我们选择的最短增广路径是 si0→ci1→si2→ci3→…→cik，则 si0 和 cik 均是不在匹配方案中的点。

我们考虑增广路径的起点 si0 可以发现：
si0≤si2，这是因为我们会给每头奶牛匹配一个尽可能大的防晒霜；
i1>i3，否则，我们可以将 ci1 和 si2 从增广路径中删除，和最短增广路径矛盾；

同理可以依次考虑 si2,si4…，可以发现如下性质：
sij≤sij+2;
ij>ij+2;
所以 ik−2>ik，所以在上述做法中，我们会先枚举到 cik，然后再枚举 cik−2，与 cik 没有匹配任何防晒霜矛盾，所以上述做法一定不存在增广路径，所以上述做法得到的匹配一定是最大匹配。

时间复杂度分析
做法第一步用快速排序即可，时间复杂度是 O(nlogn)。
做法第二步可以用 STL 中的 map 来做，核心操作是找小于等于某个数的最大的数是多少，可以借助于 upper_bound这个函数，每次操作的时间复杂度是 O(logn)O(logn)，总时间复杂度是 O(nlogn)O(nlogn)。

作者：yxc
链接：https://www.acwing.com/solution/AcWing/content/785/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */