// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
#define p u/v
typedef long long ll;
const int M = 1e7 + 10;
ll n, m, len, t, a, u, v;
int que[M], que1[M], que2[M];
int tail1, tail2, tail3, head1, head2, head3;

int find(int x)//查询第x秒最长的蚯蚓
{
	int a, b, c, d; a = b = c = d = -1;
	if (head1 <= tail1) b = que[head1] + x * len;//len即题中的q
	if (head2 <= tail2) c = que1[head2] + x * len;
	if (head3 <= tail3) d = que2[head3] + x * len;
	a = max(b, max(c, d));//比较三个队列的队首，找出最长的蚯蚓
	if (a == b) head1++;//确定是哪个队列的队首，弹出
	else {
		if (a == c) head2++;
		else head3++;
	}
	return a;
}

bool cmp(int a, int b)
{
	return a > b;
}


int main()
{
	scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &len, &u, &v, &t);
	for (int i = 1; i <= n; ++i) scanf("%d", &que[i]);
	sort(que + 1, que + 1 + n, cmp);
	tail1 = n; head1 = head2 = head3 = 1;
	for (int i = 1; i <= m; ++i) {
		int x = find(i - 1);
		if (i % t == 0) printf("%d ", x);//输出切断前的长度
		int new1 = x * p;//切断后的第一段
		int new2 = x - new1;//切断后的第二段
		que1[++tail2] = new1 - i * len;//两段分别加入队列que1[],que2[]
		que2[++tail3] = new2 - i * len;
	}
	putchar('\n');
	for (int i = 1; i <= n + m; ++i) {
		int x = find(m);//查找、输出m秒后蚯蚓的长度
		if (i % t == 0) printf("%d ", x);
	}
	return 0;
}

/*
当q>0时，除了最大值拆成的两个数之外，集合中的其它数都会增加q。
设最大值为x，不妨认为产生了两个大小为px-q和x-px-q的新数，然后再把整个集合都加上q。这与之前的操作是等价的。
于是，我们可以维护一个变量delta表示整个集合的“偏移量”，集合中的数加上delta是它的真实数值。
起初delta=0，对于每一秒：
1.取出集合中的最大值x，令x=x+delta。
2.把px-delta-q和x-px-delta-q插入集合。
3.令delta=delta+q。
重复上述步骤m轮，即可得到最终集合中所有数的值。然后本题中m的范围过大，需要一种线性算法来更快的求解。

注意到p,q是固定常数，不仅从集合中取出的数是单调递减的，新产生的两类数值也分别是随着时间单调递减的，书p55有证明。
我们可以建立三个队列A,B,C，共同构成需要维护的集合。
队列A保存出示的n个数，从大到小排序。
队列B保存每秒新产生的px那一段数值。
队列C保存每秒新产生的x-px那一段数值。
起初队列B、C为空，新产生的数从队尾插入。
根据之前的结论，B,C单调递减。因此每个时刻集合中最大的数就是队列A,B,C的三个队首之一。
再配合集合的偏移量delta，整个算法的时间复杂度为o(m+nlogn)。

 */