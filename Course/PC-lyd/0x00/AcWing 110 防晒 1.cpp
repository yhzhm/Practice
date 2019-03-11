// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int MAX = 2550;
struct node
{
	int minspf, maxspf;
	bool operator < (const node &b) const {
		if (this->minspf == b.minspf) return this->maxspf > b.maxspf;//此判断可省略
		return this->minspf > b.minspf;
	}
} cow[MAX];

struct node2
{
	int spf, cover;
	bool operator < (const node2 &b) const {
		if (this->spf == b.spf) return this->cover > b.cover;//此判断可省略
		return this->spf > b.spf;
	}
} lotion[MAX];

int C, L;

int main()
{
	cin >> C >> L;
	for (int i = 0; i < C; ++i) cin >> cow[i].minspf >> cow[i].maxspf;
	for (int i = 0; i < L; ++i)	cin >> lotion[i].spf >> lotion[i].cover;
	sort(cow, cow + C);
	sort(lotion, lotion + L);
	int ans = 0;
	for (int i = 0; i < C; ++i)
		for (int j = 0; j < L; ++j) {
			if (cow[i].minspf <= lotion[j].spf && lotion[j].spf <= cow[i].maxspf && lotion[j].cover) {
				lotion[j].cover--;
				ans++;
				break;//每头奶牛对答案的贡献至多是1，找到符合条件的防晒霜后应及时退出
			}
		}
	cout << ans << endl;
	return 0;
}
/*
每瓶防晒霜是否可用，会被奶牛的minSPF与maxSPF两个条件限制。
因为奶牛已按照minSPF递减排序，所以每一个不低于当前奶牛minSPF的值的防晒霜，都不会低于后面其它奶牛的minSPF。
那么，对于当前奶牛可用的任意两瓶防晒霜x与y，如果spf[x]<spf[y],
那么后面其它奶牛只可能出现“x，y都能用”，“x，y都不能用”，“x能用，y不能用”这三种情况。（根据x,y是否会超过奶牛的maxSPF值判断）
所以优先选择较差情况，即spf值大的y，因为选择y后，剩余防晒霜超过奶牛maxSPF的可能性更小，对于整体问题的影响比选择x更小。
另外，每头奶牛对答案的贡献至多是1。即使让当前奶牛放弃日光浴，留下防晒霜给后面的奶牛使用，对答案的贡献也不会变得更大。
综上，尽量满足当前的奶牛，并选择spf值尽量大的防晒霜是一个正确的贪心策略。
 */