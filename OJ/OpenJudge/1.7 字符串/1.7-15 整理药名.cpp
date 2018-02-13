/*
15:整理药名
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
医生在书写药品名的时候经常不注意大小写，格式比较混乱。现要求你写一个程序将医生书写混乱的药品名整理成统一规范的格式，即药品名的第一个字符如果是字母要大写，其他字母小写。如将ASPIRIN、aspirin整理成Aspirin。

输入
第一行一个数字n，表示有n个药品名要整理，n不超过100。
接下来n行，每行一个单词，长度不超过20，表示医生手书的药品名。药品名由字母、数字和-组成。
输出
n行，每行一个单词，对应输入的药品名的规范写法。
样例输入
4
AspiRin
cisapride
2-PENICILLIN
Cefradine-6
样例输出
Aspirin
Cisapride
2-penicillin
Cefradine-6
*/

// Created by Hz Yang on 2017.03
#include <cstdio>
#include <cstring>
#include <cctype>
int main()
{
	int n, len;
	char a[25];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", a);
		len = strlen(a);
		if ( islower(a[0]) ) a[0] = toupper(a[0]);
		for (int j = 1; j < len; ++j)
		{
			if ( isupper(a[j]) ) a[j] = tolower(a[j]);
		}
		puts(a);
	}
	return 0;
}