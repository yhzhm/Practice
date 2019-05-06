#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n, k;
int a[N], q[N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

	int hh = 0, tt = -1;
	for (int i = 0; i < n; i ++ )
	{
		if (hh <= tt && q[hh] < i - k + 1) hh ++ ;
		while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;
		q[ ++ tt] = i;

		if (i >= k - 1) printf("%d ", a[q[hh]]);
	}

	puts("");

	hh = 0, tt = -1;
	for (int i = 0; i < n; i ++ )
	{
		if (hh <= tt && q[hh] < i - k + 1) hh ++ ;
		while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
		q[ ++ tt] = i;

		if (i >= k - 1) printf("%d ", a[q[hh]]);
	}
	puts("");

	return 0;
}

/*
扫描两次，第一次维护一个单调递增队列，用于输出窗口中的最小值；
第二次维护一个单调递减队列，用于输出窗口中的最大值。
 */