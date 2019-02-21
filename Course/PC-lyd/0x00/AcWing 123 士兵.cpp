// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
int n, x[MAXN], y[MAXN], ans;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 1; i <= n; ++i) x[i] -= i;
	sort(x + 1, x + n + 1);
	int mid = (n + 1) >> 1;
	for (int i = 1; i <= n; ++i) ans += abs(x[i] - x[mid]) + abs(y[i] - y[mid]);
	cout << ans << endl;
	return 0;
}

/*
y轴的问题，就是“货仓选址问题”。中位数是所有点移动距离之和最小的点。
x轴的问题，目标不是点，而是序列
要求使得士兵全部相邻的最小移动次数.那么在移动前和移动后，士兵的相对位置是不变的.
举例来说,记add为移动后的最左端的士兵的前一位置，对x进行排序后
x[ 1 ] -> add + 1;
x[ 2 ] -> add + 2;
…
x[ n ] -> add + n;
转换一下
x[ 1 ] - 1 -> add;
x[ 2 ] - 2 -> add;
…
x[ n ] - n -> add;
即将所有x[i]-i移动到相同位置，将目标从序列转换成了点，
这就转化为了跟y轴一样的问题了
 */