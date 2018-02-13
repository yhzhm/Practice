/*1810: 【提高】取数
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 662解决 : 333
题目描述
设有N 个正整数（1 <= N <= 50），其中每一个均是大于等于1、小于等于300的数。
从这N个数中任取出若干个数（不能取相邻的数），要求得到一种取法，使得到的和为最大。
例如：当N=5时，有5个数分别为：13，18，28，45，21
此时，有许多种取法，如： 13，28，21 和为62
13, 45 和为58
18，45 和为63
……….
和为63应该是满足要求的一种取法。
 
输入
第一行是一个整数N 第二行有N个符合条件的整数。
 
输出
一个整数，即最大和。
 
样例输入 [复制]
5
13 18 28 45 21
样例输出 [复制]
63
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2010年江苏省小学生信息学（计算机）奥赛*/

// Created by Hz Yang on 2017/6/9.
//
#include <cstdio>
#include <iostream>

using namespace std;
int n,  c, maxd, a[25];

void dfs(int p, int sum) {
    if (p > n ) {
        maxd=max(sum,maxd);
        return;
    }
    sum+=a[p];
    dfs(p + 2, sum);
    dfs(p + 3, sum);
}

int main() {
    cin >> n ;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 0);
    dfs(2, 0);
    cout << maxd;
    return 0;
}
