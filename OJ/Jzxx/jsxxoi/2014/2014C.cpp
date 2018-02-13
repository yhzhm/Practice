/*2677: 【基础】连续非素数的最长度
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 91解决 : 53
题目描述
给出一个正整数n（2≤n≤1000000），例如n=30，在1，2，3，……30中，连续的非素数有
4	长度为1
6	长度为1
8 9 10	长度为3
12	长度为1
14 15 16 长度为3
18 长度为1
20 21 22	长度为3
24 25 26 27 28 长度为5
30	长度为1
其中，最大长度为5，即有连续的5个非素数。
 
输入
一个整数n
 
输出
一个整数，即连续非素数最大长度
 
样例输入 [复制]
12
样例输出 [复制]
3
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2014江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Hz Yang on 2017/5/24.
//
#include <iostream>

using namespace std;

bool isp(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, d = 0, count = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (isp(i)) {
            d = max(count, d);
            count = 0;
        }
        else count++;
    }
    cout << max(d, count);
    return 0;
}
