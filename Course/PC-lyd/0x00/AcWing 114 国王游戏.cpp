// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
struct num {int s, a[1100];};
struct rec {int l, r;};
num ans, now, temp;//now计算前i个人乘积，temp计算now/r[i],ans保存答案
rec a[1010];

bool operator<(rec &a, rec &b)//用于左右手数据数组排序
{
	return a.l * a.r < b.l * b.r;//根据每个人的左右手数据之积排序，最优
}

bool operator<(num &a, num &b)//高精度数组比较大小
{
	if (a.s < b.s) return true;
	if (a.s > b.s) return false;
	for (int i = a.s; i; --i) {
		if (a.a[i] < b.a[i]) return true;
		if (a.a[i] > b.a[i]) return false;
	}
}

num operator *(num &a, int &b)//高精度*int
{
	num c; int jin = 0;
	memset(&c, 0, sizeof(c));
	for (int i = 1; i <= a.s; ++i) {
		jin += a.a[i] * b;
		c.a[i] = jin % 10000;
		jin /= 10000;
	}
	c.s = a.s;
	while (jin) c.a[++c.s] = jin % 10000, jin /= 10000;//while可改为if
	return c;
}

num operator /(num &a, int &b)//高精度/int
{
	num c; int rest = 0;
	memset(&c, 0, sizeof(c));
	for (int i = a.s; i; --i) {
		rest = rest * 10000 + a.a[i];
		c.a[i] = rest / b;
		rest %= b;
	}
	c.s = a.s;
	while (c.s > 1 && !c.a[c.s]) c.s--;//c.s>1 可改为 c.s
	return c;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		cin >> a[i].l >> a[i].r;
	}
	sort(a + 1, a + n + 1);//国王不参与排序
	now.s = now.a[1] = ans.s = 1;
	for (int i = 1; i <= n; ++i) {//计算每位大臣所得金币
		now = now * a[i - 1].l;
		temp = now / a[i].r;
		if (ans < temp) ans = temp;
	}
	printf("%d", ans.a[ans.s]);//输出ans，最高位特殊处理，其余每个数占4位，不足4位的补0
	for (int i = ans.s - 1; i; --i) printf("%04d", ans.a[i]);
	puts("");
	return 0;
}