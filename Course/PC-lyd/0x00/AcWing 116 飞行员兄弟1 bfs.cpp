// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
//st起始状态，ed终止状态，vis[]记录下标表示的状态是否出现过，通过按哪个位置出现的；
//p[]记录路径，通过哪个状态转换到下标标记的状态；
//t[1~16]记录从0状态，按第1~16个位置后的状态，简化后续状态的计算。
int st, ed, vis[1 << 16], p[1 << 16], t[20];
queue< pii > q;//记录宽搜状态

int convert(int x, int y)//将第x行第y列置为1
{
	int state = 0, z;
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j) {
			z = (i == x || j == y);
			state = (state << 1) + z;
		}
	return state;
}
void init()//预处理从0状态按第1-16个位置后的状态，简化后续状态的计算
{
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j) {
			t[(i - 1) * 4 + j] = convert(i, j);
		}
}

void print(int v)//输出步骤
{
	vector<pii> path;
	while (v > 0) {
		int i = vis[v];
		int x = (i - 1) / 4 + 1, y = (i - 1) % 4 + 1;//根据数字1~16算出所在行列坐标
		path.push_back({x, y});
		v = p[v];
	}
	for (int i = path.size() - 1; i >= 0; --i) {
		cout << path[i].first << ' ' << path[i].second << endl;
	}
}

int main()
{
	char c; int x, step;//将输入时用字符表示的状态转化为用一个int的二进制位表示的状态
	for (int i = 1; i <= 16; ++i) {
		cin >> c;  x = (c == '+');
		ed = (ed << 1) + x;
	}
	init();//初始化t[]
	vis[0] = 1; q.push(make_pair(0, st));//从全0状态开始宽搜
	while (!q.empty()) {
		pii now = q.front(); q.pop();//去除当前队首
		step = now.first, x = now.second;
		if (x == ed) {//若命中，则输出
			cout << step << endl;
			print(x);
			return 0;
		}
		for (int i = 1; i <= 16; ++i) {//遍历16种摁法，保存新状态
			int v = x ^ t[i];//用x异或t[],求出从当前状态x，摁第i个位置后的状态
			if (!vis[v]) {//若是新状态，则保存
				vis[v] = i;//保存摁法
				p[v] = x;//记录路径
				q.push(make_pair(step + 1, v));//保存新状态
			}
		}
	}
	return 0;
}