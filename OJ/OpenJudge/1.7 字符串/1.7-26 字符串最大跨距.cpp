/*26:字符串最大跨距
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有三个字符串S,S1,S2，其中，S长度不超过300，S1和S2的长度不超过10。想检测S1和S2是否同时在S中出现，且S1位于S2的左边，并在S中互不交叉（即，S1的右边界点在S2的左边界点的左侧）。计算满足上述条件的最大跨距（即，最大间隔距离：最右边的S2的起始点与最左边的S1的终止点之间的字符数目）。如果没有满足条件的S1，S2存在，则输出-1。

例如，S = "abcd123ab888efghij45ef67kl", S1="ab", S2="ef"，其中，S1在S中出现了2次，S2也在S中出现了2次，最大跨距为：18。

输入
三个串：S1, S2, S3，其间以逗号间隔（注意，S1, S2, S3中均不含逗号和空格）；
输出
S1和S2在S最大跨距；若在S中没有满足条件的S1和S2，则输出-1。
样例输入
abcd123ab888efghij45ef67kl,ab,ef
样例输出
18*/

// Created by Hz Yang on 2017.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s, s1, s2, t;
	getline(cin, t);
	int x = t.find(',');
	int y = t.rfind(',');
	s = t.substr(0, x);
	s1 = t.substr(x + 1, y - x - 1);
	s2 = t.substr(y + 1, t.size() - y - 1);
	x = s.find(s1);
	y = s.rfind(s2);
	if (x != -1 && y != -1 && (x + s1.size() - 1) < y) cout << y - x - s1.size() << endl;
	else cout << "-1" << endl;
	return 0;
}