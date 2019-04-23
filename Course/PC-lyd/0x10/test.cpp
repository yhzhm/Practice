// Created by Hz Yang on 2019.04
#include <iostream>
#include <cstring>
#include <algorithm>
// #pragma GCC optimize (3)
// #pragma G++ optimize (3)
using namespace std;
typedef unsigned long long ULL;
const int M = 1010;
ULL val[M * M], p1[M], p2[M], hash_a[M][M], hash_b[M][M], tmp, ans;
int p = 0, n, m, a, b;
const ULL Pi = 131, Pj = 233;

void init()
{
	p1[0] = 1;
	p2[0] = 1;
	for (int i = 1; i <= M; ++i) {
		p1[i] = p1[i - 1] * Pj;
		p2[i] = p2[i - 1] * Pi;
	}
}

void Hash_A()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			hash_a[i][j] = hash_a[i - 1][j] * Pi + hash_a[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			hash_a[i][j] = hash_a[i][j - 1] * Pj + hash_a[i][j];

}

ULL Hash_B()
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
	init();
	scanf("%d%d%d%d\n", &n, &m, &a, &b);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) scanf("%1llu", &hash_a[i][j]);

	Hash_A();
	for (int i = a; i <= n; ++i)
		for (int j = b; j <= m; ++j) {
			tmp = hash_a[i][j];
			tmp -= hash_a[i - a][j] * p2[a];
			tmp -= hash_a[i][j - b] * p1[b];
			tmp += hash_a[i - a][j - b] * p2[a] * p1[b];
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