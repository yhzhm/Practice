//计数的变量要用long long类型
#include <bits/stdc++.h>
using namespace std;
long long lt, rt, mid, sum;
int n;
struct node
{
	long long x, y, w, h, s;
} a[10010];
long long check(long long mid)
{
	long long s1 = 0, s2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i].x + a[i].w <= mid) s1 += a[i].s;
		else if (a[i].x >= mid) s2 += a[i].s;
		else {
			s1 += (mid - a[i].x) * a[i].h;
			s2 += (a[i].w + a[i].x - mid) * a[i].h;
		}
	}
	return s1 - s2;
}
int main()
{
	long long r;
	cin >> r >> n;
	long long maxx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].w >> a[i].h;
		a[i].s = a[i].w * a[i].h;
		if (a[i].x + a[i].w > maxx) maxx = a[i].x + a[i].w;
	}
	lt = 0; rt = r;
	while (rt - lt > 1) {
		mid = (lt + rt) / 2;
		sum = check(mid);
		if (sum > 0) rt = mid;
		else if (sum <= 0) lt = mid;
	}
	long long zuo, you, ans;
	zuo = check(lt);
	you = check(rt);
	if (abs(zuo) >= abs(you)) ans = rt;
	else ans = lt;
	if (ans == maxx)ans = r;
	cout << ans << endl;
	return 0;
}
