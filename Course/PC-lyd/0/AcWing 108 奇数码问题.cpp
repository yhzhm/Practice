// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int a[N * N], b[N * N], c[N * N];
int cnt;
void merge(int a[], int l, int r)
{
	if (r - l < 1) return;
	int mid = (r + l) >> 1;
	merge(a, l, mid);
	merge(a, mid + 1, r);
	int i = l, j = mid + 1;
	for (int k = l; k <= r; ++k) {
		if (j > r || (i <= mid && a[i] <= a[j])) c[k] = a[i++];
		else c[k] = a[j++], cnt += mid - i + 1;
	}
	for (int k = l; k <= r; ++k) a[k] = c[k];
}
int main()
{
	int n, x, ans1, ans2;
	while (cin >> n) {
		int len = n * n, t = 0;
		for (int i = 1; i <= len; ++i) {
			cin >> x;
			if (x) a[++t] = x;//输入0时不存储
		}
		t = 0;
		for (int i = 1; i <= len; ++i) {
			cin >> x;
			if (x) b[++t] = x;//输入0时不存储
		}
		//辅助变量、辅助数组初始化，通过归并排序求逆序对数量
		cnt = 0, memset(c, 0, sizeof c);
		merge(a, 1, len - 1), ans1 = cnt;
		cnt = 0, memset(c, 0, sizeof c);
		merge(b, 1, len - 1), ans2 = cnt;
		//判断奇偶性是否相同
		if ((ans1 & 1) == (ans2 & 1)) puts("TAK");
		else puts("NIE");
	}
	return 0;
}
/*
左右交换时，不影响整个数列的逆序对数量；
上下交换时，相当于某个数与它前（后）边的n-1个数交换了位置，
影响了n-1个数，因为n是奇数，所以逆序对数量的变化只能是偶数；
根据以上分析可得出结论：
奇数码游戏两个局面可达，当且仅当两个局面下网格中的数依次写成一行n*n-1个元素的序列后（不考虑空格），
逆序对个数的奇偶性相同。
 */