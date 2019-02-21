// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int m = 1e9;
struct num {int s, a[300];};
num fa[60010], fb[60010];

num operator +(num &a, num &b)
{
	num c; int jin = 0;
	memset(&c, 0, sizeof(c)) ;
	int max_s = max(a.s, b.s);
	for (int i = 1; i <= max_s; ++i) {
		jin += a.a[i] + b.a[i];
		c.a[i] = jin % m;
		jin /= m;
	}
	c.s = max_s;
	if (jin) c.a[++c.s] = jin;
	return c;
}

int main()
{
	int n; cin >> n;
	for (int j = 0; j <= n + 1; ++j) fa[j].s = fa[j].a[1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			fb[j] = fa[j + 1] + fb[j - 1];
		}
		memcpy(fa, fb, sizeof(num) * (n + 1) );
	}
	num ans = fa[0];
	printf("%d", ans.a[ans.s]);
	for (int i = ans.s - 1; i; --i) printf("%09d", ans.a[i]);
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