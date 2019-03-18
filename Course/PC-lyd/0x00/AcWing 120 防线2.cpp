// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int n;
struct Seq {int s, e, d;} seqs[M];

int get_sum(int x)//当前位置的前缀和
{
	int res = 0;
	for (int i = 0; i < n; i++)//遍历所有点
		if (seqs[i].s <= x) res += (min(seqs[i].e, x) - seqs[i].s) / seqs[i].d + 1;
	return res;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int l = 0, r = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {//读入每段的s，e，q,将最大的e作为r
			int s, e, q;
			scanf("%d%d%d", &s, &e, &q);
			seqs[i] = {s, e, q};
			r = max(r, e);
		}

		while (l < r) {//因为奇数的点有且仅有1个，所以前缀和的奇偶性具有单调性，以此二分求奇数点
			int mid = l + r >> 1;
			if (get_sum(mid) & 1) r = mid;
			else l = mid + 1;
		}

		auto sum = get_sum(r) - get_sum(r - 1);//求二分到的点的防具数量
		if (sum % 2) printf("%d %d\n", r, sum);
		else puts("There's no weakness.");
	}
	return 0;
}