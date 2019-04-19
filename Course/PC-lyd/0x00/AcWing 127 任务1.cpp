// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
typedef pair<int, int> pii;
pii a[M], b[M];//a[]保存机器，b[]保存任务
int cnt[105];//下标表示机器级别，统计相应级别可用机器数
long long ans1, ans2;
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
	for (int i = 0; i < m; ++i) cin >> b[i].first >> b[i].second;
	sort(a, a + n); sort(b, b + m);
	for (int now = n - 1, i = m - 1; i >= 0; --i) {//now=n-1机器，i=m-1任务，倒序贪心
		while (now >= 0 && a[now].first >= b[i].first) {//查找满足时间要求的机器
			cnt[a[now].second]++;
			now--;
		}
		for (int j = b[i].second; j <= 100; ++j) {//在满足时间条件的机器中，找等级最低的机器使用
			if (cnt[j]) {
				cnt[j]--; ans1++;
				ans2 += b[i].first * 500 + b[i].second * 2;
				break;
			}
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
/*
贪心
因为时间占比大，所以以时间为第一排序条件，机器级别为第二排序条件
 */