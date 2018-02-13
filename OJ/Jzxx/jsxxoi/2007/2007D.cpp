/*1726: 【基础】求数位上的数字
时间限制 : 2 Sec内存限制 : 64 Mb提交 : 832解决 : 189
题目描述
给出二个整数N和K，求出N 的K次方的结果中的十位数和个位数的数字。
 
输入
二个整数N, K（2≤N，K≤100000000 ）。
 
输出
二个数字（分别表示N 的K次方结果中的十位数和个位数的数字，用一个空格分隔）。
 
样例输入 [复制]
3 6
样例输出 [复制]
2 9
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2007年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/18.
// 简化运算，先求出第二个乘数的10位（y）和个位（x），计算结果对100取余
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int x, y, s = n % 100;
    x = n % 10;
    y = ((n % 100) / 10) * 10;
    n %= 100;
//    cout << n << ' ' << x << ' ' << y << endl;

    for (int i = 2; i <= k; ++i) {
        s = s * x + s * y;
        s %= 100;
    }
    cout << s / 10 << ' ' << s % 10;
    return 0;
}