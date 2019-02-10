// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500010;
int T, n, m, p[N];
ll b[N], a[N], t;
void merge(int l, int mid, int r)//归并排序
{
	int i = l, j = mid;
	for (int k = l; k <= r; ++k) {
		if (j > r || (i < mid && a[i] <= a[j])) b[k] = a[i++];
		else b[k] = a[j++];
	}
}
bool check(int l, int mid, int r)
{
	for (int i = mid; i <= r; ++i) a[i] = p[i];//复制倍增部分到a[]
	sort(a + mid , a + r + 1);//排序倍增部分
	merge(l, mid, r);//归并倍增部分至b[]
	ll sum = 0;
	for (int i = 0; i < (r - l + 1) >> 1 && i < m; i++)//计算“区间长度的一半”次
		sum += (b[r - i] - b[l + i]) * (b[r - i] - b[l + i]);
	if (sum <= t) {//符合条件，保存排序好的数据
		for (int i = l; i <= r; ++i)
			a[i] = b[i];
		return true;
	}
	else return false;
}
int batch(int st)//st为新段的起始点
{
	int len = 1, r = st;
	a[st] = p[st];
	while (len) {
		if (r + len <= n && check(st, r + 1, r + len)) {
			r += len;
			len <<= 1;//倍增
			if (r == n) break;
		} else len >>= 1;//倍减
	}
	return r + 1;//返回下一段的起始点
}
int main()
{
	cin >> T;
	while (T--) {//T组数据
		cin >> n >> m >> t;
		for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
		int ans = 0;
		for (int i = 1; i <= n; i = batch(i) , ans++);
		cout << ans << endl;
	}
	return 0;
}