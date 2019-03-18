// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int t[maxn], a[maxn], n, m;
char s1[maxn], s2[maxn];
void solve()
{
	int i, len, k = 0, p = 0;
	len = strlen(s1);
	for (i = 0; i < len; ++i) //将输入数字的各位转化为10进制数字:55=65-10;61=97-10-26;
		t[i] = s1[i] - (s1[i] < 58 ? 48 : (s1[i] < 97 ? 55 : 61));//顺序存储
	while (p < len) {
		for (i = p; i < len - 1; ++i) {
			t[i + 1] += t[i] % m * n;//进位保存至高位(高位在右)
			t[i] /= m;
		}
		a[k++] = t[len - 1] % m;//每处理一遍，得到输出数的1位（从低位到高位）
		t[len - 1] /= m;
		while (p < len && !t[p]) p++;//忽略左侧0；
	}
	s2[k] = '\0';
	for (i = 0; i < k; ++i)//逆序转换各位为字母
		s2[k - 1 - i] = a[i] + (a[i] < 10 ? 48 : (a[i] < 36 ? 55 : 61));
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &m, s1);
		solve();
		printf("%d %s\n%d %s\n\n", n, s1, m, s2);
	}
	return 0;
}
/*
和1的方法一样，只是处理的时候没有逆序
 */