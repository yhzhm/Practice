/*
17:字符串判等
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
判断两个由大小写字母和空格组成的字符串在忽略大小写，且忽略空格后是否相等。

输入
两行，每行包含一个字符串。
输出
若两个字符串相等，输出YES，否则输出NO。
样例输入
a A bb BB ccc CCC
Aa BBbb CCCccc
样例输出
YES
*/
// Created by Hz Yang on 2017.03
#include <cstdio>
#include <cstring>
#include <cctype>
int main()
{
	char a[1000], b[1000], c[1000], d[1000];
	gets(a); gets(b);
	int lena = strlen(a);
	int lenb = strlen(b);
	int j = 0, k = 0, flag = 1;
	for (int i = 0; i < lena; ++i) {
		if (isalpha(a[i])) c[j++] = toupper(a[i]);
	}
	for (int i = 0; i < lenb; ++i) {
		if (isalpha(b[i])) d[k++] = toupper(b[i]);
	}
	if (j != k) flag = 0;
	else {
		for (int i = 0; i < j; ++i)
			if (c[i] != d[i]) {flag = 0; break;}
	}
	if (flag) printf("YES");
	else printf("NO");

	return 0;
}

