// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;

int d[N];

int main()
{
	int n, p, h, m;
	set<pair<int, int>> existed;//用来判重
	cin >> n >> p >> h >> m;
	d[1] = h;//对应的前缀和序列中每个元素都为h
	// for (int i = 0; i < N; ++i) cout << d[i] << ' ';
	// cout << endl;
	for (int i = 0, a, b; i < m; i ++ )
	{
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (!existed.count({a, b}))//.count返回集合中元素个数，在set中只能为0或1
		{
			existed.insert({a, b});
			d[a + 1] --, d[b] ++ ;//将区间内所有数减1
		}
	}

	for (int i = 1; i <= n; i ++ )
	{
		d[i] += d[i - 1];//根据差分数列求前缀和数列，即变化后的原数列
		cout << d[i] << endl;
	}
	return 0;
}


/*


 */