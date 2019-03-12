// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 10;
const double eps = 1e-6, INF = 1e10;//eps用于保证浮点数精度
typedef pair<double, double> PDD;
int n, R;
PDD segs[M];//存储从岛屿x,y坐标转化得到的线段范围

int main()
{
	bool success = true;

	cin >> n >> R;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (y > R) {
			success = false;
			break;
		}

		double len = sqrt(R * R - y * y);
		segs[i] = {x + len, x - len};//按线段右端点从小到大排序，所以first是x+len
	}

	if (!success) puts("-1");
	else {
		sort(segs, segs + n);
		int res = 0; double last = -INF;//last：上一个雷达位置
		for (int i = 0; i < n; ++i) {
			auto seg = segs[i];
			if (seg.second > last + eps) {//second:左端点，first：右端点
				res++;
				last = seg.first;
			}
		}
		cout << res << endl;
	}
	return 0;
}

/*
(贪心) O(nlogn)
如下图所示，对于任意一个小岛 (x,y)，我们都可以在海岸线上求出能覆盖该小岛的建造雷达的区间 [a,b]。
由勾股定理可知：
a=x−sqrt(d^2−y^2);
b=x+sqrt(d^2−y^2);
将所有小岛转化成区间后，问题转化为：给定 n 个区间，在 x 轴上选择尽量少的点，使得所有区间至少包含一个点。

我们先给出做法，再证明其正确性。

算法步骤：
1.将所有区间按右端点从小到大排序；
2.依次考虑每个区间：
如果当前区间包含最后一个点，则直接跳过；
如果当前区间不包含最后一个点，则在当前区间的右端点的位置选一个新的点；

证明：
首先上述做法一定可以保证所有区间都至少包含一个点。
然后我们再证明这样选出的点的数量是最少的，不妨设选出的点数是 m：
按照上述做法，我们选择的点都是某个区间的右端点，而且由于区间按右端点排好序了，所以我们选择的点也是排好序的；
只有在当前区间和上一个点所对应的区间是没有交集时，我们才会选择一个新点，所以所有选出的点所对应的区间是如下图所示的情况，两两之间没有交集。
所以我们找到了 m 个两两之间没有交集的区间，因此我们至少需要选 m 个点。而且通过上述做法，我们可以只选 m 个点。因此最优解就是 m。

时间复杂度
计算每个坐标所对应的区间，需要 O(n) 的计算量；
将所有区间排序需要 O(nlogn) 的计算量；
扫描所有区间需要 O(n) 的计算量；
所以总共的时间复杂度是 O(nlogn)。
*/