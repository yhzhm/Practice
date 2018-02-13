/*
03:基因相关性
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
为了获知基因序列在功能和结构上的相似性，经常需要将几条不同序列的DNA进行比对，以判断该比对的DNA是否具有相关性。

现比对两条长度相同的DNA序列。首先定义两条DNA序列相同位置的碱基为一个碱基对，如果一个碱基对中的两个碱基相同的话，则称为相同碱基对。接着计算相同碱基对占总碱基对数量的比例，如果该比例大于等于给定阈值时则判定该两条DNA序列是相关的，否则不相关。

输入
有三行，第一行是用来判定出两条DNA序列是否相关的阈值，随后2行是两条DNA序列（长度不大于500）。
输出
若两条DNA序列相关，则输出“yes”，否则输出“no”。
样例输入
0.85
ATCGCCGTAAGTAACGGTTTTAAATAGGCC
ATCGCCGGAAGTAACGGTCTTAAATAGGCC
样例输出
yes
*/

#include <cstdio>
#include <cstring>
int main()
{
	int sum = 0, i = 0, len;
	double n;
	char a[500 + 10], b[500 + 10];
	scanf("%lf\n", &n);
	gets(a);
	gets(b);
	len = strlen(a);
	for (i = 0; i < len; i++) {
		if (a[i] == b[i]) sum++;
	}
	if ((double)sum / len >= n) printf("yes");
	else printf("no");
	return 0;
}
