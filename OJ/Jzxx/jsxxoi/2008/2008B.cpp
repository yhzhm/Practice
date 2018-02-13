/*1729: 【基础】整数串拆段
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 495解决 : 238
题目描述
将一个长度小于11位的数字串拆成2段，使其和为最小的素数。
例如数字串‘13304’
拆的方法有:
1 + 3304 = 3305
13 + 304 = 317
133 + 04 = 137
1330 + 4 = 1334
从上面可看出，和为素数的有：317 与137，最小的是137
 
输入
一个长度小于15的数字串
 
输出
最小的和为素数的数，若无素数则输出 -1
 
样例输入 [复制]
13304
样例输出 [复制]
137
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2008年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/19.
//
#include <cstdio>
#include <iostream>

using namespace std;

bool isp(long long n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    string s;
    bool flag = 0;
    long long n, m, minx = 0x7fffffff;
    cin >> s;
    for (int i = 0; i < s.size() - 1; ++i) {
        n = 0;
        m = 0;
        for (int j = 0; j <= i; ++j) {
            n = n * 10 + (s[j] - 48);
        }
        for (int k = i + 1; k < s.size(); ++k) {
            m = m * 10 + (s[k] - 48);
        }
        if (isp(n + m)) {
            minx = min(n + m, minx);
            flag = 1;
        }
    }
    if (flag) cout << minx;
    else cout << "-1";
    return 0;
}


