/*1271: 【基础】求无暇素数
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 879解决 : 231
题目描述
一个两位整数A本身是素数，若将其个位数字与十位数字交换，得到一个新的两位数B，而B也是素数，我们则称A为无暇素数。 例如：31是素数，个位数字与十位数字交换后得到13，也是素数。所以31是无暇素数。 问题： 给出一个数字字符串（即字串中的字符全部由数字组成），求出其所有组成的无暇素数。
 
输入
一个数字字符串（长度<＝20），以“%”结束。
 
输出
全部的无暇素数，之间用一个逗号隔开。
 
样例输入 [复制]
321314%
样例输出 [复制]
13,31
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2003年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/12.
//
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

bool isp(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    string s;
    int a[20], first = 1,x1,x2;
    cin >> s;
    int n = s.size()-1;
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 48;
    }
    for (int j = 0; j < n - 1; ++j) {
        x1=a[j] * 10 + a[j + 1];
        if (isp(x1)) {
            x2 = a[j + 1] * 10 + a[j];
            if (isp(x2)) {
                if (first) {
                    cout << x1;
                    first = 0;
                } else cout << ',' << x1;
            }
        }
    }
    return 0;
}


