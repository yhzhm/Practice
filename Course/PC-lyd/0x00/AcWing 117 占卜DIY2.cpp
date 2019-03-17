// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 14;
vector<int> cards[M];//读入13堆牌
int open[M];//记录牌面向上的牌数

int get(char c)
{
	if (c == 'A') return 1;
	if (c >= '2' && c <= '9') return c - '0';
	if (c == '0') return 10;
	if (c == 'J') return 11;
	if (c == 'Q') return 12;
	return 13;
}

int main()
{
	for (int i = 1; i <= 13; ++i) {//读入13行
		for (int j = 0; j < 4; ++j) {//每行读入4次
			char s[2];
			cin >> s;
			cards[i].push_back(get(*s));
		}
	}
	for (int i = 0; i < 4; ++i) {
		int t = cards[13][i];//取第13堆的牌
		while (t != 13) {
			open[t]++;
			int r = cards[t].back();//直接赋值给t会报错
			cards[t].pop_back();
			t = r;
		}
	}

	int res = 0;
	for (int i = 1; i <= 12; ++i) res += (open[i] == 4);
	cout << res << endl;
	return 0;
}