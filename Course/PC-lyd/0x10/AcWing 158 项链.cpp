// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
const int M = 2e6 + 10;
char a[M], b[M];

int calc(char *s)
{
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) s[n + i] = s[i];//s复制一份接在结尾
	int i = 1, j = 2, k;
	while (i <= n && j <= n) {
		for (k = 0; k < n && s[i + k] == s[j + k]; ++k);
		if (k == n) break;//s只由1种字符构成
		if (s[i + k] > s[j + k]) {//去掉i~k之间的可能子串
			i = i + k + 1;
			if (i == j) i++;
		} else {//去掉j~k之间的可能子串
			j = j + k + 1;
			if (i == j) j++;
		}
	}
	return min(i, j);
}

int main()
{
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	int n = strlen(a + 1), x = calc(a);
	int m = strlen(b + 1), y = calc(b);
	a[x + n] = b[y + m] = 0;
	if (n == m && !strcmp(a + x, b + y)) puts("Yes"), puts(a + x);
	else puts("No");
	return 0;
}