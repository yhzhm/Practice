// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
int sum[M], f[M], s1[M], s2[M], p1, p2;//sum[]前缀和，f[]前缀和最大值，s1,s2栈1栈2,p1,p2指针
int main()
{
	char c[10];
	int T, x;
	f[0] = INT_MIN;//擂主，因为有负数，取最小值
	scanf("%d", &T);
	while (T--) {
		scanf("%s", c);
		switch (c[0]) {
		case 'I'://插入
			scanf("%d", &x);
			s1[++p1] = x;//入栈1
			sum[p1] = sum[p1 - 1] + x;//求前缀和
			f[p1] = max(f[p1 - 1], sum[p1]);//求前缀和最大值
			break;
		case 'D'://删除
			if (p1) p1--;//若s1非空，出栈
			break;
		case 'L'://左移
			if (p1) s2[++p2] = s1[p1], p1--;//若s1非空，将s1栈顶压入s2
			break;
		case 'R'://右移
			if (p2) {//若s2非空，将s2栈顶压入s1，更新sum[],f[]
				s1[++p1] = s2[p2];
				sum[p1] = sum[p1 - 1] + s2[p2];
				f[p1] = max(f[p1 - 1], sum[p1]);
				p2--;
			}
			break;
		case 'Q'://o(1)输出前缀和最大值
			scanf("%d", &x);
			printf("%d\n", f[x]);
			break;
		default: break;
		}
	}
	return 0;
}