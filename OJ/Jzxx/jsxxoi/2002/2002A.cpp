/*1266: 【基础】字典排序
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 1009解决 : 615
题目描述
输入N（N<=10）个不超过4位的整数，并要求按字典顺序（字典顺序的方法：先比较第一个数字，小者在先，若相同再比较第2位数字，以此类推），由小到大排序输出。
 
输入
第一行为一个整数N 第2-N+1行为N个不超过4位的整数
 
输出
一行，按字典顺序由小到大排序输出这N个整数。
 
样例输入 [复制]
5
13
130
39
27
4
样例输出 [复制]
13 130 27 39 4
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2002江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Hz Yang on 2017/6/12.
//
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n;
    string s[15];
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        cin >> s[i];
    }
    sort(s,s+n);
    for (int i = 0; i < n; ++i) {
        cout << s[i] <<' ';
    }
    return 0;
}

