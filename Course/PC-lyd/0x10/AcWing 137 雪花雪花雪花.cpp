// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE = 100010, P = 99991;//P为最接近SIZE的质数
int n, tot, snow[SIZE][6], head[SIZE], nex[SIZE];//i=head[H(a)]=在snow中的行数，nex[i]=i行链接的行
int H(int *a)//计算哈希值
{
	int sum = 0, mul = 1;
	for (int i = 0; i < 6; ++i) {
		sum = (sum + a[i]) % P;
		mul = 1ll * mul * a[i] % P;
	}
	return (sum + mul) % P;
}
bool equal(int *a, int *b)//判断两片雪花形状是否相同
{
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j) {
			bool eq = 1;
			for (int k = 0; k < 6; ++k) {//顺时针
				if (a[(i + k) % 6] != b[(j + k) % 6]) eq = 0;//可以break简单优化
			}
			if (eq) return true;
			eq = 1;
			for (int k = 0; k < 6; ++k) {//逆时针
				if (a[(i + k) % 6] != b[(j - k) % 6]) eq = 0;
			}
			if (eq) return true;
		}
	return false;
}
bool insert(int *a)
{
	int val = H(a);
	for (int i = head[val]; i; i = nex[i]) {//在val值相同的雪花中查找。i为0时不执行
		if (equal(snow[i], a)) return true;
	}
	++tot;//未找到形状相同的雪花，执行插入
	memcpy(snow[tot], a, 6 * sizeof(int));//插入到(覆盖)snow数组的第tot行
	nex[tot] = head[val];//更新链表
	head[val] = tot;//更新表头
	return false;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a[6];
		for (int j = 0; j < 6; ++j) cin >> a[j];//输入一个雪花数据
		if (insert(a)) {//查找，若未找到则插入
			puts("Twin snowflakes found.");
			return 0;
		}
	}
	puts("No two snowflakes are alike.");
	return 0;
}
/*
对于两片形状相同的雪花，它们六个角的长度之和、长度之积都相等，因此它们的hash函数值也相等。
但反之不一定成立，所以要且只要在hash函数值相同的雪花中进行查找即可，
用head[hash[a]]记录头结点（在snow数组中是第几行），
用next[i]记录第i行后面是哪一行（hash值相同的雪花才记录在一个链表中）。
 */