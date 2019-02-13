// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
int st, t[20];//t[1~16]记录从0状态，按第1~16个位置后的状态，简化后续状态的计算。
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
			t[(i - 1) * 4 + j] = convert(i, j);//t[]的坐标{1,1}时为1，{4,4}时为16
		}
}

void print(int cnt, int state) //根据state计算输出摁的点坐标
{
	cout << cnt << endl; //输出步骤次数
	for (int i = 15; i >= 0; --i) {//从左往右，最左侧位置要右移15位
		if (state >> i & 1) {
			int x = 4 - i / 4, y = 4 - i % 4;//所需坐标逆序要进行逆序转换
			cout << x << ' ' << y << endl;
		}
	}
}

int main()
{
	char c; int x;//将输入时用字符表示的状态转化为用一个int的二进制位表示的状态
	for (int i = 1; i <= 16; ++i) {
		cin >> c;  x = (c == '+');
		st = (st << 1) + x;
	}
	init();
	for (int i = 1; i < (1 << 16); ++i) {//枚举所有摁法，用一个int的二进制表示摁哪些位置
		int temp = st, cnt = 0;
		for (int j = 0; j < 16; ++j) {
			if (i >> j & 1) {
				temp = temp ^ t[16 - j];//注意：t[]的顺序和右移位数是相反的，若init时做相反顺序处理，则不需要；
				cnt++;
			}
		}
		// cout << i << ' ' << temp << endl;
		if (!temp) {print(cnt, i); break;}
	}
	return 0;
}