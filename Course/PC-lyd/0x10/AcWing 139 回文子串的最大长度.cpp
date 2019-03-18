// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
typedef unsigned long long ULL;//2^64作为模值
char s[M];
ULL f1[M], f2[M], p[M];//f1[]前缀和，f2[]后缀和，p[]进制权值

ULL H(int i, int j)//用前缀和计算左半部分字符哈希值
{
	return f1[j] - f1[i - 1] * p[j - i + 1];
}

ULL H2(int i, int j)//用后缀和计算右半部分字符哈希值
{
	return f2[i] - f2[j + 1] * p[j - i + 1];
}

int main()
{
	int ans = 0, cases = 0; p[0] = 1;//131^0
	for (int i = 1; i < M; ++i) p[i] = p[i - 1] * 131;//预处理权值
	while (1)
	{
		++cases; ans = 0;
		scanf("%s", s + 1);//从下标1开始读入字符串
		int len = strlen(s + 1);
		if (len == 3 && s[1] == 'E' && s[2] == 'N' && s[3] == 'D') break;
		f2[len + 1] = 0;//末尾置为0，便于就按后缀和
		for (int i = 1; i <= len; ++i) f1[i] = f1[i - 1] * 131 + (s[i] - 'a' + 1);//前缀和
		for (int i = len; i >= 1; --i) f2[i] = f2[i + 1] * 131 + (s[i] - 'a' + 1);//后缀和
		for (int pos = 1; pos <= len; ++pos)//遍历所有位置
		{
			int l = 0, r = min(pos - 1, len - pos); //奇回文
			while (l < r) {//二分求最长回文长度
				int mid = (l + r + 1) >> 1;
				if (H(pos - mid, pos - 1) == H2(pos + 1, pos + mid)) l = mid;
				else r = mid - 1;
			}
			ans = max(ans, l * 2 + 1);

			l = 0, r = min(pos - 1, len - pos + 1);//偶回文
			while (l < r) {//二分求最长回文长度
				int mid = (l + r + 1) >> 1;
				if (H(pos - mid, pos - 1) == H2(pos, pos + mid - 1)) l = mid;
				else r = mid - 1;
			}
			ans = max(ans, l * 2);
		}
		printf("Case %d: %d\n", cases, ans);
	}
	return 0;
}