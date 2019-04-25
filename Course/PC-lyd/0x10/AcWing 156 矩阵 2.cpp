// Created by Hz Yang on 2019.04
#include <iostream>
#include <cstring>
#include <algorithm>
#pragma GCC optimize (2)//不开o2超时
// #pragma G++ optimize (3)
using namespace std;
typedef unsigned long long ULL;//mod 2^64
const int M = 1010;
// val[]:存储子矩阵哈希值，p1[]:存储131进制权值，p2[]:存储233进制权值
ULL val[M * M], p1[M], p2[M], hash_a[M][M], hash_b[M][M], tmp, ans;
int p = 0, n, m, a, b;
const ULL Pi = 131, Pj = 233;

void Hash_A()//计算矩阵a的哈希值
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)//每列（131)哈希值之和
			hash_a[i][j] = hash_a[i - 1][j] * Pi + hash_a[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)//将列相加，得到二维哈希值之和
			hash_a[i][j] = hash_a[i][j - 1] * Pj + hash_a[i][j];
}

ULL Hash_B()//计算矩阵b的哈希值
{
	for (int i = 1; i <= a; ++i)
		for (int j = 1; j <= b; ++j)
			hash_b[i][j] = hash_b[i - 1][j] * Pi + hash_b[i][j];
	for (int i = 1; i <= a; ++i)
		for (int j = 1; j <= b; ++j)
			hash_b[i][j] = hash_b[i][j - 1] * Pj + hash_b[i][j];
	return hash_b[a][b];
}

int main()
{
	p1[0] = 1; p2[0] = 1;//初始化p1，p2权值
	for (int i = 1; i <= M; ++i) {
		p1[i] = p1[i - 1] * Pi;//p1:行（计算列）
		p2[i] = p2[i - 1] * Pj;//p2:列（计算行）
	}

	scanf("%d%d%d%d\n", &n, &m, &a, &b);
	for (int i = 1; i <= n; ++i)//1llu:读入1位无符号longlong数
		for (int j = 1; j <= m; ++j) scanf("%1llu", &hash_a[i][j]);

	Hash_A();
	for (int i = a; i <= n; ++i)//计算出每个子矩阵的哈希值
		for (int j = b; j <= m; ++j) {
			tmp = hash_a[i][j];
			tmp -= hash_a[i - a][j] * p1[a];//减掉多余行
			tmp -= hash_a[i][j - b] * p2[b];//减掉多余列
			tmp += hash_a[i - a][j - b] * p1[a] * p2[b];//加上重复减掉的部分
			val[++p] = tmp;
		}

	int q, flag = 1;
	scanf("%d", &q);
	while (q --) {
		for (int i = 1; i <= a; ++i)
			for (int j = 1; j <= b; ++j) scanf("%1llu", &hash_b[i][j]);
		ans = Hash_B(); flag = 1;
		for (int i = 1; i <= p; ++i)
			if (val[i] == ans) {puts("1"); flag = 0; break;}
		if (flag) puts("0");
	}
	return 0;
}