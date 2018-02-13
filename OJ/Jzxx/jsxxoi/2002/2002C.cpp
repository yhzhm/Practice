/*1270: 【基础】求二进制数的最大公约数与最小公倍数
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 489解决 : 268
题目描述
输入二个二进制整数（长度不超过20位），求出其最大公约数与最小公倍数，并用二进制数输出。
 
输入
两行，每行一个二进制整数。
 
输出
一行，用二进制数表示的最大公约数与最小公倍数，用空格隔开。
 
样例输入 [复制]
11
100
样例输出 [复制]
1 1100
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2002江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Hz Yang on 2017/6/12.
// 因为二进制位数有20位，当做整数读入会超范围，所以用字符串读入

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int b2i(string s) {
    int x = 1, sum = 0;
    sum += x * (s[s.size() - 1] - 48);
    for (int i = s.size() - 2; i >= 0; --i) {
        x = x * 2;
        sum += x * (s[i] - 48);
    }
    return sum;
}

int gcd(int x, int y) {
    if (x % y == 0) return y;
    gcd(y, x % y);
}

void printb(int n) {
    stack<int> s;
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    string s1, s2;
    int n;
    cin >> s1 >> s2;
    int x = b2i(s1), y = b2i(s2);
    if (x >= y) n = gcd(x, y);
    else n = gcd(y, x);
    printb(n);
    cout << ' ';
    printb(n * (x / n) * (y / n));
    return 0;
}

