// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m = 1e9;
struct num {int s; ll a[120010];};
num ans;

void operator *(num &a, ll &b)//不传参，直接计算
{
	ll jin = 0;
	for (int i = 1; i <= a.s; ++i) {
		jin += a.a[i] * b;
		a.a[i] = jin % m;
		jin /= m;
	}
	while (jin) a.a[++a.s] = jin % m, jin /= m;
}

void operator /(num &a, ll &b)//高精度除以int
{
	ll rest = 0;
	for (int i = a.s; i; --i) {
		rest = rest * m + a.a[i];
		a.a[i] = rest / b;
		rest %= b;
	}
	while (a.s > 1 && !a.a[a.s]) a.s--;//c.s>1 可改为 c.s
}

int main()
{
	int n; cin >> n;
	ans.s = ans.a[1] = 1;
	for (int i = 2; i <= n; ++i) {
		ll x = i + n;
		ans * x;
	}
	for (ll i = 2; i <= n; ++i)
		ans / i ;
	printf("%lld", ans.a[ans.s]);
	for (int i = ans.s - 1; i; --i) printf("%09lld", ans.a[i]);
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