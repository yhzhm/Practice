// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;//电影数量
int b[MAXN], c[MAXN];//b、c分别统计会电影语音和字幕的人数
unordered_map<int, int> mp;//用map会超时
struct node {
	int pos, lan, sub;//电影编号、语音人数、字幕人数
	//操作符重载，也可以写cmp函数
	bool operator<(const node &B) const
	{
		if (lan == B.lan) return sub > B.sub;
		return lan > B.lan;
	}
} a[MAXN];
int main()
{
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		mp[x]++;//用mp离散统计语言人数
	}
	int m; cin >> m;
	for (int i = 0; i <= m; ++i) {
		scanf("%d", &x);
		a[i].pos = i + 1;//保存编号
		a[i].lan = mp[x];//保存该电影能听懂语音的人数
	}
	for (int i = 0; i <= m; ++i) {
		scanf("%d", &x);
		// a[i].pos = i + 1;//电影编号保存一次就可以了
		a[i].sub = mp[x];//保存该电影能看懂字幕的人数
	}
	sort(a, a + m);
	cout << a[0].pos << endl;
	return 0;
}