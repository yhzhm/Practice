// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int d[15], f[15];
	//推出3塔的情况
	d[1] = 1;
	//d[i-1]+1+d[i-1]
	//将i-1个盘子移到一根柱子上（中转柱）+将最大号盘子移到目标柱+将i-1个盘子从中转柱移到目标柱
	for (int i = 2; i <= 12; ++i) {
		d[i] = 1 + d[i - 1] * 2;
	}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;//0个盘子的移动步数
	//f[j]+d[i-j]+f[j]
	//将前j个盘子移到一根中转柱，此时是4塔，所以步数是f[j]
	//将剩余i-j个盘子移到目标柱，此时放j个盘子的中转塔不能用，所以是3塔，步数是d[i-j]
	//将j个盘子从中转塔移到目标塔，此时又是4塔，所以步数是f[j]
	for (int i = 1; i <= 12; ++i) {
		for (int j = 0; j < i; ++j) {
			f[i] = min(f[i], f[j] * 2 + d[i - j]);
		}
	}
	for (int i = 1; i <= 12; ++i)
		cout << f[i] << endl;
	return 0;
}