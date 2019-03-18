// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 3e5 + 10;
typedef unsigned long long ULL;
ULL f[M], p[M];
int sa[M], rk[M], height[M], n;
char s[M];

ULL get(int l, int r)
{
	return f[r] - f[l - 1] * p[r - l + 1];
}

int lcp(int x, int y)
{
	int l = 0, r = min(n - x + 1, n - y + 1);
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (get(x, x + mid - 1) == get(y, y + mid - 1)) l = mid;
		else r = mid - 1;
	}
	return l;
}

bool cmp(int x, int y)
{
	int len = lcp(x, y);
	return s[x + len] < s[y + len];
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	p[0] = 1;
	for (int i = 1; i <= n; ++i) {
		sa[i] = i;
		f[i] = f[i - 1] * 131 + (s[i] - 'a' + 1);
		p[i] = p[i - 1] * 131;
	}
	sort(sa + 1, sa + n + 1, cmp);
	for (int i = 2; i <= n; ++i) height[i] = lcp(sa[i - 1], sa[i]);
	for (int i = 1; i <= n; ++i) printf("%d ", sa[i] - 1); printf("\n");
	for (int i = 1; i <= n; ++i) printf("%d ", height[i]); printf("\n");
	return 0;
}