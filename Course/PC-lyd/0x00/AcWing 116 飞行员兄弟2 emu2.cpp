// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;

typedef pair<int, int> PII;

int change[4][4];

int get(int x, int y)
{
	return x * 4 + y;
}

int main()
{
	int state = 0;
	for (int i = 0; i < 4; ++i) { //将读入的状态转化为一个整数的二进制表示
		string s;
		cin >> s;
		for (int j = 0; j < 4; j++)
			if (s[j] == '+') state += (1 << get(i, j));
	}

	for (int i = 0; i < 4; ++i) //预处理change[][]
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				change[i][j] += (1 << get(i, k));
				change[i][j] += (1 << get(k, j));
			}
			change[i][j] -= (1 << get(i, j));
		}

	vector<PII> res;
	for (int k = 0; k < (1 << 16); ++k) {
		int now = state;
		vector<PII> path;
		for (int i = 0; i < 16; ++i)
			if (k >> i & 1) {
				int x = i / 4, y = i % 4;
				now ^= change[x][y];
				path.push_back({x, y});
			}
		if (!now && (res.empty() || res.size() > path.size())) res = path;
	}
	cout << res.size() << endl;
	for (auto p : res) cout << p.first + 1 << ' ' << p.second + 1 << endl;
	return 0;
}