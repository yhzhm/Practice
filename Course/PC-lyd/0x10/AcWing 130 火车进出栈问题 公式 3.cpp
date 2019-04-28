// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9;
ll a[60010], c[120010];
int n, p;

void factor(int n, int flag)//分解(质)因数，统计在c[]中，分母flag=1，分子flag=-1
{
	for (int i = 2; i * i <= n; ++i)
		while (n % i == 0) c[i] += flag, n /= i;
	if (n) c[n] += flag;
}

void calc(ll x)//高精度计算，所有因数相乘
{
	for (int i = 1; i <= p; ++i) a[i] *= x;
	for (int i = 1; i <= p; ++i) a[i + 1] += a[i] / M, a[i] %= M;
	while (a[p + 1]) ++p;
}

int main()
{
	a[1] = p = 1; cin >> n;
	for (int i = 2; i <= n; ++i) factor(n + i, 1), factor(i, -1);//n+2~n+n的因素+1统计，2~n的因数-1统计
	for (int i = 2; i <= n << 1; ++i)//将所有剩余因数相乘
		for (ll j = 0; j < c[i]; ++j) calc(i);
	printf("%lld", a[p]);//输出
	for (int i = p - 1; i; --i) printf("%09lld", a[i]);
	puts("");
	return 0;
}

/*
Python大法好：
import math
n = int(input())
print(math.factorial(n*2)//(math.factorial(n)*math.factorial(n))//(n+1))
 */

/*
公式：第n项卡特兰数 C(n,2*n)/(n+1)
 */

/*
动归：
F[i][j]表示有i个数尚未进栈，目前有j个数在栈里，已经有n-i-j个数出栈时的方案总数
边界：F[0][0]=1,目标：F[N][0]
每一步的两种决策分别是“把一个数进栈”和“把栈顶的数出栈”，所以有公式：
F[i,j]=F[i-1,j+1]+F[i][j-1];
 */

/*
//递推：sn=Σs(k-1)*s(n-k) (k=1~n)  WR，需要高精度
#include <bits/stdc++.h>
using namespace std;
int a[60010], n;
int main()
{
	cin >> n;
	a[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			a[i] += a[j - 1] * a[i - j];
		}
	}
	cout << a[n] << endl;
	return 0;
}
*/