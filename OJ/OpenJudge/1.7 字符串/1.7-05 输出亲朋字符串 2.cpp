// Created by Hz Yang on 2017.03
#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[105], c[105];
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
	{
		printf("%c", s[i] + s[(i + 1) % len] );
	}
	return 0;
}
