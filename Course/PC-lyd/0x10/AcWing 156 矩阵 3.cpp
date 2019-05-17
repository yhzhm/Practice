#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef unsigned long long ULL;

const int N = 1010, M = N * N, P = 131;

int n, m, a, b;
ULL h[N][N], p[M];
char str[N];

ULL get(ULL f[], int l, int r)
{
	return f[r] - f[l - 1] * p[r - l + 1];
}

int main()
{
	cin >> n >> m >> a >> b;

	p[0] = 1;
	for (int i = 1; i <= n * m; i ++ ) p[i] = p[i - 1] * P;
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j ++ ) h[i][j] = h[i][j - 1] * P + str[j] - '0';
	}

	unordered_set<ULL> S;
	for (int i = b; i <= m; i ++ )
	{
		ULL s = 0;
		int l = i - b + 1, r = i;
		for (int j = 1; j <= n; j ++ )
		{
			s = s * p[b] + get(h[j], l, r);
			if (j > a) s -= get(h[j - a], l, r) * p[a * b];
			if (j >= a) S.insert(s);
		}
	}

	int k;
	cin >> k;
	while (k -- )
	{
		ULL s = 0;
		for (int i = 0; i < a; i ++ )
		{
			scanf("%s", str);
			for (int j = 0; j < b; j ++ ) s = s * P + str[j] - '0';
		}

		if (S.count(s)) puts("1");
		else puts("0");
	}

	return 0;
}

/*
将m*n的矩阵里所有a*b的矩阵哈希成一个数字
 */