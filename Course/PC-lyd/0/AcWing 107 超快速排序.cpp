// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, a[N], b[N];
long long cnt;//结果可能是N的平方
void merge(int l, int r)
{
	if (r - l < 1) return;
	int mid = (l + r) >> 1;
	merge(l, mid);
	merge(mid + 1, r);
	int i = l, j = mid + 1;
	for (int k = l; k <= r; ++k) {
		//如果右半区已合并完，或左半区数小于右半区数
		if (j > r || (i <= mid && a[i] <= a[j]) ) b[k] = a[i++];
		else b[k] = a[j++], cnt += mid - i + 1;//左半区剩余的数，都能和右半区的当前j位置数构成逆序对
	}
	for (int k = l; k <= r; ++k) a[k] = b[k];//从备份数组b[]还原
}
int main()
{
	while (cin >> n && n) {
		cnt = 0;//统计逆序对数量
		for (int i = 1; i <= n; ++i) cin >> a[i];
		merge(1, n);//归并排序
		cout << cnt << endl;
	}
	return 0;
}