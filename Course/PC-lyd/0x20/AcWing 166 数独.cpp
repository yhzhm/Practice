// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
using namespace std;
char str[10][10];//数独矩阵
int row[9], col[9], grid[9]; //数独矩阵有9行9列9个子矩阵
int cnt[512], num[512], tot; //512=2^9，9位2进制表示

int g(int x, int y)//根据行号和列号，计算当前格子属于第哪个子矩阵
{
	return ((x / 3) * 3) + (y / 3);
}

void change(int x, int y, int z)//处理后，剩下的1表示可填之数
{
	row[x] ^= 1 << z;
	col[y] ^= 1 << z;
	grid[g(x, y)] ^= 1 << z;
}

bool dfs(int now)
{
	if (now == 0) return true;
	int temp = 10, x, y;
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			if (str[i][j] != '.') continue;
			int val = row[i] & col[j] & grid[g(i, j)];
			if (!val) return false; //无数字可填
			if (cnt[val] < temp) temp = cnt[val], x = i, y = j; //打擂台，找可填数字少的格子
		}
	int val = row[x] & col[y] & grid[g(x, y)];
	for (; val; val -= val & -val) { //枚举当前格子的可填数字
		int z = num[val & -val];
		str[x][y] = '1' + z; //填数
		change(x, y, z);
		if (dfs(now - 1)) return true;
		change(x, y, z); //再change一次，相当于还原，还原row，col，grid信息
		str[x][y] = '.'; //还原数独矩阵
	}
	return false;
}

int main()
{
	for (int i = 0; i < 1 << 9; ++i) //统计数i的二进制表示中，有多少个1
		for (int j = i; j; j -= j & -j) cnt[i]++; //j & -j:lowbit,等价于 j ^= j & -j
	for (int i = 0; i < 9; ++i) num[1 << i] = i; //哈希二进制权值
	string s;
	while (cin >> s, s != "end") {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) str[i][j] = s[i * 9 + j];
		for (int i = 0; i < 9; ++i) row[i] = col[i] = grid[i] = (1 << 9) - 1;
		tot = 0;
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (str[i][j] != '.') change(i, j, str[i][j] - '1');
				else tot++;
		dfs(tot);
		for (int i = 0; i < 9; ++i) cout << str[i];
		cout << endl;
	}
	return 0;
}