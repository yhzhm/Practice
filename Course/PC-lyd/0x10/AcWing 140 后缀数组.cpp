// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 3e5 + 10;
typedef unsigned long long ULL;//2^64
ULL f[M], p[M];//f[]字符串哈希值，p[]进制权值
int sa[M], height[M], n;//sa[]排序字符位置，height[]相邻位置后缀字符串的最长公共前缀
char s[M];//读入字符串

ULL get(int l, int r)//计算区间l~r的哈希值
{
	return f[r] - f[l - 1] * p[r - l + 1];
}

int lcp(int x, int y)//计算位置x和位置y的后缀的最长公共前缀长度
{
	int l = 0, r = min(n - x + 1, n - y + 1);//两个后缀的较短长度
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (get(x, x + mid - 1) == get(y, y + mid - 1)) l = mid;
		else r = mid - 1;
	}
	return l;
}

bool cmp(int x, int y)//二分求出公共前缀长度，然后比较第一个不同位置，用于排序
{
	int len = lcp(x, y);
	return s[x + len] < s[y + len];
}

int main()
{
	scanf("%s", s + 1);//从位置1开始读入
	n = strlen(s + 1);//字符串长度
	p[0] = 1;//131^0
	for (int i = 1; i <= n; ++i) {//遍历字符串中的每个字符
		sa[i] = i;//存储位置
		f[i] = f[i - 1] * 131 + (s[i] - 'a' + 1);//计算字符串哈希值
		p[i] = p[i - 1] * 131;//计算权值
	}
	sort(sa + 1, sa + n + 1, cmp);//按后缀字符串的字典序排序
	for (int i = 2; i <= n; ++i) height[i] = lcp(sa[i - 1], sa[i]);//计算height[]
	for (int i = 1; i <= n; ++i) printf("%d ", sa[i] - 1); printf("\n");//输出：从0~n-1
	for (int i = 1; i <= n; ++i) printf("%d ", height[i]); printf("\n");
	return 0;
}