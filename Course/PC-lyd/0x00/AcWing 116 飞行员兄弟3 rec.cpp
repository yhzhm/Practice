// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
int res[5][5];
int main() {
	char c;
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) {
			cin >> c;
			if (c == '+') {
				for (int k = 1; k <= 4; ++k)
					res[i][k] ^= 1, res[k][j] ^= 1;
				res[i][j] ^= 1;//i,j被多摁了一次，所以这里再摁回来。
			}
		}
	}
	int cnt = 0;//统计次数
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			if (res[i][j])
				++cnt;
	cout << cnt << endl;
	for (int i = 1; i <= 4; ++i)//按顺序输出坐标
		for (int j = 1; j <= 4; ++j)
			if (res[i][j])
				cout << i << " " << j << endl;
	return 0;
}
/*
将所在行、列每个点都按一遍，行列上的其它点被摁的次数为4=0，非行列上的点被摁的次数为2=0
该点被摁7次=1次；
故可推出方法：要改变一个点的状态，将该点所在行、列上的点都摁一次即可。
 */