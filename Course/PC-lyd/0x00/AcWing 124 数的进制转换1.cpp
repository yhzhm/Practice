// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int t[maxn], a[maxn], n, m;//t[]保存由输入转换成的数字，a[]记录输出进制的结果
char s1[maxn], s2[maxn];//s1输入，s2输出
void solve()
{
	int len, k = 0;
	len = strlen(s1);
	for (int i = len - 1; i >= 0; --i) //从len开始也可以
		//将输入数字的各位转化为10进制数字:55=65-10;61=97-10-26;
		t[len - 1 - i] = s1[i] - (s1[i] < 58 ? 48 : (s1[i] < 97 ? 55 : 61));//逆序存储
	while (len) {
		for (int i = len - 1; i >= 1; --i) { //从len开始也可以
			t[i - 1] += t[i] % m * n;//进位保存至高位（高位在前）
			t[i] /= m;
		}
		a[k++] = t[0] % m;//每处理一遍，得到输出数的1位（从低位到高位）
		t[0] /= m;
		while (len > 0 && !t[len - 1]) len--;//去掉右侧的0（低位）
	}
	s2[k] = '\0';//字符串结束标识
	for (i = 0; i < k; ++i)//逆序转换各位为字母
		s2[k - 1 - i] = a[i] + (a[i] < 10 ? 48 : (a[i] < 36 ? 55 : 61));
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &m, s1);
		printf("%d %s\n\n", n, s1);
		solve();
		printf("%d %s\n%d %s\n\n", n, s1, m, s2);
	}
	return 0;
}