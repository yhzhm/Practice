// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int a[MAXN], s[MAXN], n;//a[]保存输入数据，s[]计算前缀和
long long sum, ave, ans;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int ave = sum / n;
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i] - ave;//减去平均值以后的前缀和
	}
	sort(s + 1, s + n + 1);//因为是圆圈，所以排序后的中位数是最佳断点
	int mid = s[n >> 1 | 1];
	for (int i = 1; i <= n; ++i) {
		ans += abs(s[i] - mid);
	}
	printf("%lld\n", ans);
	return 0;
}