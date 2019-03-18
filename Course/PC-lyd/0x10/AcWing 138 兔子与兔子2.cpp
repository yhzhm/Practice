// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
char s[M];
unsigned long long f[M], p[M];//f[]前缀和，p[]进制权值
int main()
{
	scanf("%s", s + 1);//前缀和从1开始处理，所以从下标1开始读，便于后续计算前缀时统一下标
	int n = strlen(s + 1), m;
	cin >> m;
	p[0] = 1;//131^0
	for (int i = 1; i <= n; ++i) {
		f[i] = f[i - 1] * 131 + (s[i] - 'a' + 1);
		p[i] = p[i - 1] * 131;
	}
	while (m--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (f[r1] - f[l1 - 1]*p[r1 - l1 + 1] == f[r2] - f[l2 - 1]*p[r2 - l2 + 1])
			puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
68ms
s1=1~r ,s2=1~(l-1)
s1-s2时，将s2左移r-l+1位(r-(l-1))，即将s1*p^(r-l+1)后再相减

 */