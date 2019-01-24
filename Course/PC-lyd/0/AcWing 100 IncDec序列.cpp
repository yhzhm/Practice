// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010;
int a[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = n; i > 1; i--) a[i] -= a[i - 1];

	LL pos = 0, neg = 0;
	for (int i = 2; i <= n; ++i)
		if (a[i] > 0) pos += a[i];
		else neg -= a[i];//减去负数，求到的是负数的绝对值
	cout << max(pos, neg) << endl;
	// cout << min(pos, neg) + abs(pos - neg) << endl;
	cout << abs(pos - neg) + 1 << endl;
	return 0;
}

/*
差分可以理解为前缀和的逆运算
a[1],a[2], ... ,a[n]
b[i] = a[i] - a[i-1], b[1] = a[1]
b[]是a[]的差分序列，a[]是b[]的前缀和序列
a[i] = b[1] + b[2] + ... + b[i]
	 = a[1] + a[2] - a[1] + a[3] - a[2] + ... + a[i] - a[i-1]
	 = a[i]
差分序列的作用：
给区间[l,r]加上一个常数C
b[l] += C,b[r+1] -= C
这个操作是可以看做是o(1)的，比对l,r区间操作提高了效率
这样操作后，对于前缀和来说，l之前和r之后没有影响，在l和r之间加了C
题目目标：
在b[]中选两个点，一个+1，一个-1，
经过多次操作后，b[2...n]中元素值一样
可用操作：选2个数，一加一减
1. 2<=i,j<=n
2. i=1,2<=j<=n 把某个前缀整个进行操作
3. 2<=i<=n,j=n+1 把某个后缀进行操作
4. i=1,j=n+1 对整个序列操作，在本题中没有意义

 */