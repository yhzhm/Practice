// Created by Hz Yang on 2019.02
#include<bits/stdc++.h>
using namespace std;
int n, a[20], cnt;
bool check()//检查是否合法，当前数后面所有比它小的数都应该是倒序的
{
	for (int i = 0; i < n; ++i) {
		int can_mx = a[i];
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[i]) {//当前数后面所有比它小的数
				if (a[j] > can_mx) return false;
				else can_mx = a[j];
			}
		}
	}
	return true;
}
void print()
{
	for (int i = 0; i < n; ++i) cout << a[i];//输出
	cout << endl;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[i - 1] = i;
	do {
		if (cnt >= 20) break;//输出前20个
		if (check()) print(), cnt++;//若合法，输出、计数
	} while (next_permutation(a, a + n));//全排列
	return 0;
}
/*
在全排列中检查是否合法
枚举+判断
判断原理：一个序列是出栈序列，当且仅当较大值出站后，后续的小值依次出栈。
 */