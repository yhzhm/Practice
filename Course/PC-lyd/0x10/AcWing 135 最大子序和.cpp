// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 3e5;
int a[M], q[M], n, m;//a[]输入值，q[]需维护的单调队列
ll sum[M], ans;//sum[]前缀和
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = 1;//q[]的指针，q[]中存储sum[]下标
	q[l] = 0;//save choice j=0
	for (int i = 1; i <= n; ++i) {//维护q[]在m范围内，且单调递增
		while (l <= r && q[l] < i - m) l++;//step 1
		ans = max(ans, sum[i] - sum[q[l]]);//step 2
		while (l <= r && sum[q[r]] >= sum[i]) r--;//step 3
		q[++r] = i;
	}
	printf("%lld\n", ans);
	return 0;
}

/*
区间和问题，一般转化为两个前缀和相减的形式进行求解。
原问题可以转化为：找出两个位置x,y，使s[y]-s[x]最大并且y-x<=m.
当右端点i固定时，问题就变为：找到一个左端点j，其中j∈[i-m,i-1]并且s[j]最小。
比较任意两个位置j和k，如果k<j<i并且s[k]>=s[j]，那么对于所有大于i的右端点，k永远不会成为最优选择。
因为不但s[k]不小于s[j]，而且j离i更近，长度更不容易超过m，即j的生存能力比k更强。
所以当j出现后，k就完全是一个无用的位置。
所以，可能成为最优解的策略集合一定是一个“下标位置递增、对应的前缀和s的值也递增”的序列。
随着右端点从前向后扫描，我们对每个i执行以下三个步骤：
1.判断队头决策与i的距离是否超过m的范围，若超出则出队。
2.等1维护完毕，此时队头就是右端点为i时，左端点j的最优选择，更新答案。
3.不断删除队尾决策，直到队尾对应的s值小于s[i]。然后把i作为一个新的决策入队。
sum[i]-min{sum[j]|i-m~i-1};
这就是著名的单调队列算法，它的思想也是“在决策集合（队列）中及时排除一定不是最优解的选择”。
单调队列是优化动态规划的一个重要手段。

 */