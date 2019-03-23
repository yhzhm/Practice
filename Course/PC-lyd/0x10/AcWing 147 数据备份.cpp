// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
int f[M], a[M], pre[M], Next[M], v[M];//f:堆,a:读入及计算、保存区间，pre:前项，Next：后项，v[x]:值x在f[]中的下标位置
int n, m, p, x, ans;//p:堆中坐标，x：节点值

void up(int p)//向上调整
{
	while (p > 1) {
		if (a[f[p]]<a[f[p >> 1]]) {//子节点<父节点时，不满足小根堆性质，交换
			swap(f[p], f[p >> 1]);//交换节点
			swap(v[f[p]], v[f[p >> 1]]);//同时交换v[]值
			p >>= 1;//位置更新为父节点位置
		}
		else break;
	}
}

void down(int l, int r)//向下调整，l：调整节点所在位置，r：末尾节点位置
{
	int t = 2 * l;//l的左子节点
	while (t <= r) {
		if (t < r && a[f[t]] > a[f[t + 1]]) t++;//左右子节点中取较大者
		if (a[f[l]] > a[f[t]]) {//父节点大于子节点，不满足小根堆性质
			swap(f[l], f[t]);
			swap(v[f[l]], v[f[t]]);
			l = t, t = 2 * l;
		}
		else break;
	}
}

void insert(int x)//x:a[]的下标
{
	f[++p] = x;//放在堆最后
	v[x] = p;//记录x在堆中的位置
	up(p);//向上调整
}

void erase(int x)
{
	f[v[x]] = f[p];//当前节点替换成末尾节点
	v[f[p]] = v[x];//更新v
	p--;//删除末尾元素
	up(v[x]), down(v[x], p);//此时既有可能需要向上调整，也有可能需要向下调整
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i < n; ++i) {
		a[i] = a[i + 1] - a[i];
		Next[i] = i + 1, pre[i + 1] = i;
		insert(i);//将a[]下标插入堆
	}
	for (int i = 1; i <= m; ++i) {
		x = f[1]; ans += a[x];
		if (pre[x] == 0 && Next[x] == n) break;
		if (pre[x] == 0) {//上边界
			erase(x), erase(Next[x]);
			pre[Next[Next[x]]] = 0;
		} else if (Next[x] == n) {//下边界
			erase(x), erase(pre[x]);
			Next[pre[pre[x]]] = n;
		} else {
			erase(x), erase(pre[x]), erase(Next[x]);
			a[x] = a[pre[x]] + a[Next[x]] - a[x];
			insert(x);
			pre[x] = pre[pre[x]]; Next[pre[x]] = x;
			Next[x] = Next[Next[x]]; pre[Next[x]] = x;
		}
	}
	cout << ans << endl;
	return 0;
}