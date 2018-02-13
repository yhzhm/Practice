/*2883: 【提高】方格取数
时间限制 : 1 Sec内存限制 : 128 Mb提交 : 54解决 : 36
题目描述
在 n 行、m 列的方格矩阵中，每个方格都包含一个数字。小明可以从任意方格出发开始移动。每次移动可以移到与当前方格有一条边相邻的方格(即向上、下、左或右方向移动 1 格，且不能移出边界)。除此之外，你移动到的方格中的数字必须比当前方格中的数字更大。
请你帮助小明编程规划移动路径，使路径上经过的所有数字之和最大。
本题方格中的数据根据输入的初始数字 s 按照如下算法生成:
for i = 1, 2, ... n
  for j = 1, 2, ... m
    s ← (s × 345) mod 19997
矩阵第 i 行第 j 列方格中的数字为(s mod 10) + 1
 
输入
正整数 n, m (方格的大小), s (数据生成器的初始数值)。1 ≤ n,m ≤ 100，1 ≤ s ≤ 19,997。
 
输出
所有合法路径中的最大数字和。
 
样例输入
样例1: [复制]
4 5 97
样例2: [复制]
40 50 1
样例输出
样例1: [复制]
24
样例2: [复制]
47*/
//
// Created by Hz Yang on 2017/5/3.
//
#include <iostream>

using namespace std;
int n, m, s, sum = 0, a[105][105];
int maxi = ~((unsigned) (-1) >> 1);
//int mini = 0x7fffffff;
//int maxi = 0x80000000;

void dfs(int i, int j, int x) {
    if (i > 0 && i <= n && j > 0 && j <= m) {
        if (a[i][j] > x) {
            sum += a[i][j];
            maxi = maxi > sum ? maxi : sum;
            dfs(i + 1, j, a[i][j]);
            dfs(i, j + 1, a[i][j]);
            dfs(i - 1, j, a[i][j]);
            dfs(i, j - 1, a[i][j]);
            sum -= a[i][j];
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s = s * 345 % 19997;
            a[i][j] = (s % 10) + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dfs(i, j, 0);
        }
    }
    cout << maxi << endl;
    return 0;
}
