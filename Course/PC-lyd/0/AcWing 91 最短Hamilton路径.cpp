// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
const int N = 20, M = 1 << 20;//全局变量和静态变量会开在堆空间而非栈空间（4M）
int n;
int f[M][N], weight[N][N];//f[i][j]表示状态是i的时候，停在点j，此时的最短路径是多少
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> weight[i][j];
		}
	}
	memset(f, 0x3f, sizeof f);//0x3f3f3f3f这个数，两数相加略小于int型最大值
	f[1][0] = 0;//[1]表示只有0号点的时候状态是1,[0]表示在0号点，还没有走任何路程
	for (int i = 0; i < 1 << n; ++i)
		for (int j = 0; j < n; ++j)
			if (i >> j & 1) {//判断i的二进制表示中，第j位是否是1，也就是i表示的集合中，是否包含j
				for (int k = 0; k < n; ++k) {
					if (i >> k & 1) //包含k
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);//排除j，等价于：i ^ 1 << j
				}
			}
	cout << f[(1 << n) - 1][n - 1] << endl;//[(1 << n) - 1]表示所有点都遍历过了，并且最后停在n-1这个点
	return 0;
}
/*
只要考虑：
1.哪些点被用过
2.目前停在哪个点上

2^20*20=2*10^7
枚举state,枚举从哪个点转移过来，假设是从k点转移过来的话
f[state][j]=f[state_k][k]+weight[k][j],state_k=state除掉j之后的集合，state_k要包含k
+weight[k][j]表示加上从k到j的距离
20位整数表示state集合，即状态压缩
时间复杂度=状态数量*状态转移次数
运算量：2*10^7 * 20 约4亿次，题目时限是7s，约7亿次
*/
