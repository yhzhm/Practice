/*1806: 【提高】数的分解
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 1007解决 : 80
题目描述
一个正整数N（4 <= N <= 10000）可以分解为K 个正整数的和（2 <= K <= 10， K<=N）。
 
输入
N K
 
输出
一个整数，即N 能够分为K 个正整数和的分法个数。
 
样例输入 [复制]
6 3
样例输出 [复制]
3
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2010年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/9.
//
#include <cstdio>
#include <iostream>

using namespace std;
int n, k, c;

void dfs(int p, int b, int e) {
    if (p == k) {
        c++;
        return;
    }
    for (int i = b; i <= e; ++i) {
        if (i <= e - i) dfs(p + 1, i, e - i);
    }
}

int main() {
    cin >> n >> k;
    dfs(1, 1, n);
    cout << c;
    return 0;
}

