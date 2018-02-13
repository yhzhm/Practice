/*1272: 【基础】求P进制数的最大公因子与最小公倍数
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 318解决 : 190
题目描述
有两个P进制的整数A，B，求出A，B的最大公因子与最小公倍数，并仍以P进制数的形式输出。
 
输入
一行，为P A B。（2≤P≤9）
 
输出
两行 第一行为最大公因子 第二行为最小公倍数
 
样例输入 [复制]
2 110 1001
样例输出 [复制]
(110,1001)＝11
[110,1001]＝10010
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2003年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/12.
// 数据范围不大，所以可以当做整数读入，然后再处理
#include <cstdio>
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int p, a, b;

int p2i(int n) {
    int s = 0, i = 0;
    while (n > 0) {
        s += (n % 10) * pow(p, i);
        i++;
        n /= 10;
    }
    return s;
}

int i2p(int n) {
    int sum = 0;
    stack<int> s;
    while (n > 0) {
        s.push(n % p);
        n /= p;
    }
    while (!s.empty()) {
        sum = sum * 10 + s.top();
        s.pop();
    }
    return sum;
}

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    if (x % y == 0) return y;
    gcd(y, x % y);
}

int main() {
    cin >> p >> a >> b;
    int ia = p2i(a), ib = p2i(b);
    int x = gcd(ia, ib);
    int y = x * (ia / x) * (ib / x);
    printf("(%d,%d)=%d\n", a, b, i2p(x));
    printf("[%d,%d]=%d\n", a, b, i2p(y));
    return 0;
}


