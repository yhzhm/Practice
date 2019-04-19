// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
const int M = 10010;
int n, x[M], y[M];

int work(int *a)
{
	int res = 0;
	sort(a, a + n);
	for (int i = 0; i < n; ++i) res += abs(a[i] - a[i / 2]);//同abs(a[i]-a[n/2])
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n ; ++i) scanf("%d%d", &x[i], &y[i]);
	sort(x , x + n );
	for (int i = 0; i < n; ++i) x[i] -= i;

	cout << work(x) + work(y) << endl;
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