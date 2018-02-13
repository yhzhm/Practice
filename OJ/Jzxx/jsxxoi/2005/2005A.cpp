/*1714: 【基础】回文数个数
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 1027解决 : 712
题目描述
如果一个正整数从左向右读与从右向左读均是一样，则称其为回文数。例如3、121、3223、12021都是回文数。
 
输入
任意给定一个正整数n（0 < n <= 100000 ）
 
输出
一个正整数，表示[1,n]之间的回文数的个数。
 
样例输入 [复制]
325
样例输出 [复制]
41
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2005年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/14.
//
#include <cstdio>
#include <iostream>

using namespace std;

int n, a[15][15], s, cnt;

bool palindrome(int n) {
    int x = n, s = 0;
    while (x > 0) {
        s = s * 10 + x % 10;
        x /= 10;
    }
    return s == n;
}

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cnt += palindrome(i);
    }
    cout << cnt;
    return 0;
}
