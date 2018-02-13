/*2877: 【基础】求回文数
时间限制 : 1 Sec内存限制 : 128 Mb提交 : 176解决 : 142
题目描述
一个正整数，正读和反读都相同的数为回文数。例如22，131，2442，37073，6，…所有1位数都是回文数。给出一个正整数n（1≤n≤10000），求出1,2,…,n之中（包括1和n）的回文数的个数。
输入
一个整数n
输出
一个整数，即1,2,…,n中全部回文数的个数。
样例输入 [复制]
24
样例输出 [复制]
11
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2015江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Hz Yang on 2017/5/16.
//
#include <iostream>

using namespace std;

bool check(int n) {
    if (n >= 1 && n <= 9) return true;
    int x = n, sum = 0;
    while (x > 0) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return sum == n;
}

int main() {
    int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (check(i)) count++;
    }
    cout << count << endl;
    return 0;
}
