/*1269: 【基础】求三角形与梯形个数
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 390解决 : 276
题目描述
给出如下图的图形：
 
 问能组成多少个三角形、多少个梯形（不包括三角形个数）
 
输入
m n （二个整数， 1< m,n <=20）
 
输出
三角形个数 梯形个数
 
样例输入 [复制]
7 6
样例输出 [复制]
105 210
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2002江苏省青少年信息学奥林匹克小学组竞赛复*/

//
// Created by Hz Yang on 2017/6/12.
//
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int x = m * (m - 1) / 2;
    int y = (n - 1) * (n - 2) / 2;
    cout << x * (n - 1) << ' ' << x * y;
    return 0;
}

