// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int MAX = 200010;
int s[MAX], e[MAX], d[MAX];
int main()
{
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) scanf("%d%d%d", &s[i], &e[i], &d[i]);
		unsigned int l = 0, r = 0x7fffffff, mid, ans = 0, sum;
		while (l < r) {
			mid = (l + r) >> 1; sum = 0;
			for (int i = 1; i <= n; ++i) {//计算mid点的前缀和（防具个数）
				if (mid >= s[i]) {
					if (mid < e[i]) sum += (mid - s[i]) / d[i] + 1;
					else sum += (e[i] - s[i]) / d[i] + 1;
				}
			}
			//根据前缀和二分答案
			if (sum & 1) r = mid; else l = mid + 1;
		}
		for (int i = 1; i <= n; ++i)//统计命中点防具数量
			if ((s[i] <= l) && (l <= e[i]) && ((l - s[i]) % d[i] == 0)) ans++;
		if (ans & 1) printf("%d %d\n", l, ans);		else puts("There's no weakness.");
	}
	return 0;
}
/*
二分
因为只有一个点的防具数量为奇数，所以可以通过前缀和进行二分
若mid点为奇数，则右侧都是奇数，答案在左侧；
否则，答案在右侧；
 */