/*2682: 【提高】取数
时间限制 : 1 Sec内存限制 : 128 Mb提交 : 68解决 : 23
题目描述
有n个数（2≤n≤100）排成一排，从n个数中任取若干个数，取数规则为每次取相邻的2个数，不能取1个，也不能取多于2个连续的数，找一种取法，使取到数的和为最大。
例如：n=6 6个数
13 2 17 14 8 16
取数方法有
13 2 14 8 和为 37
13 2 8 16 和为 39
2 17 8 16 和为 43
17 14 和为 37
其中和最大的为43
 
输入
第1行一个整数n
第2行n个整数 xi（x1 x2…….xn）（1≤i≤100）
 
输出
一个整数，即合理取法中最大的和。
 
样例输入 [复制]
6
13 2 17 14 8 16
样例输出 [复制]
43
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2014江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Yhz on 2017/5/31.
//
#include <iostream>

using namespace std;

int n, a[105], maxsum;

void dfs(int i, int sum) {
    if (i + 1 > n) {
        maxsum = max(sum, maxsum);
        return;
    }
    sum += a[i] + a[i + 1];
    dfs(i + 3, sum);
    dfs(i + 4, sum);
    dfs(i + 5, sum);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 0);
    dfs(2, 0);
    dfs(3, 0);
    cout << maxsum;
    return 0;
}
