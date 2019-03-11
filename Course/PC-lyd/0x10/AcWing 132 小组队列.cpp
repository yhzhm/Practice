// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int  M = 1e7;
deque<int> q[1010];//deque有clear，queue没有clear
int c[M + 10], n, m, x, t;//c[]哈希存储数字的小组编号
char s[10];//读入命令
int main()
{
	while (cin >> n && n)	{//可用scanf
		for (int i = 0; i <= n; ++i) q[i].clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &m);//读入m个数，小组编号为i
			for (int j = 1; j <= m; ++j) scanf("%d", &x), c[x] = i;
		}
		printf("Scenario #%d\n", ++t);
		while (~scanf("%s", s) && s[0] != 'S')	{//~可去掉
			if (s[0] == 'E') {
				scanf("%d", &x);//小组若为空，在q[0]队列中记录小组编号
				if (!q[c[x]].size()) q[0].push_back(c[x]);//可用empty()替代
				q[c[x]].push_back(x);//插入所在小组
			}
			else {
				x = q[0].front();//q[0]中队首小组
				printf("%d\n", q[x].front());//输出该小组的队首元素
				q[x].pop_front();//弹出
				if (!q[x].size()) q[0].pop_front();//若小组为空，将该小组编号弹出q[0]队列
			}
		}
		puts("");
	}
	return 0;
}
/*
用empty()时不用取反有区别
 */