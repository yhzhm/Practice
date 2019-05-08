// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10010, M = 80;

int n, m;
char str[N][M];
int Next[N];
bool st[M];//循环节长度

int main()
{
	cin >> n >> m;

	memset(st, true, sizeof st);

	for (int i = 1; i <= n; ++i) {
		scanf("%s", str[i]);
		for (int j = 1; j <= m; ++j) //枚举循环节长度为j时能否成立
			if (st[j]) {
				for (int k = j; k < m; k += j) {
					for (int u = 0; u < j && k + u < m; u++)
						if (str[i][u] != str[i][k + u]) {
							st[j] = false; break;
						}
					if (!st[j]) break;
				}
			}
	}

	int width;
	for (int i = 1; i <= m; ++i)
		if (st[i]) {
			width = i;
			break;
		}

	for (int i = 1; i <= n; ++i) str[i][width] = 0;

	for (int i = 2, j = 0; i <= n; ++i) {
		while (j && strcmp(str[i], str[j + 1])) j = Next[j]; //strcmp相等返回0，小于返回-1，大于返回1
		if (!strcmp(str[i], str[j + 1])) j++;
		Next[i] = j;
	}

	int height = n - Next[n];

	cout << width*height << endl;
	return 0;
}