// Created by Hz Yang on 2019.01
// 输出n的二进制表示中，位是1的位置编号。
// n & -n 等价于lowbit(n),取出非负整数n在二进制表示下最低位的1以及它后面的0构成的数值
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1 << 20;
int H[MAX_N + 1];

int main()
{
	int n;
	for (int i = 0; i <= 20; ++i) H[1 << i] = i;//预处理
	while (cin >> n) {//对多次询问进行求解
		while (n > 0) {
			cout << H[n & -n] << ' ';
			n -= n & -n;//等价于：n ^= n & -n;
		}
		cout << endl;
	}
	return 0;
}
