// Created by Hz Yang on 2019.02
#include<bits/stdc++.h>
using namespace std;
const int M = 30;
int n, p1, p2, cnt;//p1栈a指针，p2栈b指针，cnt计数
int a[M], b[M];//栈a用来模拟入栈，b[]保存出栈数据

void print()
{
	for (int i = 1; i <= n; ++i) cout << b[i];
	cout << endl;
}

void dfs(int k)
{
	if (p2 == n) {//出栈数等于n时输出
		cnt++; print();
		if (cnt == 20) exit(0);
		return;
	}
	if (p1 > 0) {//k进栈前，站内元素出栈
		int tp = a[p1--];
		b[++p2] = tp;
		dfs(k);
		a[++p1] = tp;
		p2--;
	}
	if (k <= n) {//然后再入栈
		a[++p1] = k;
		dfs(k + 1);
		p1--;
	}
}

int main() {
	cin >> n;
	dfs(1);//从第1个数开始，搜索第k个数
	return 0;
}
/*
对于一个数k要进栈，先让栈内的元素考虑出栈，然后再入栈。
当出栈数等于n时，输出。
 */