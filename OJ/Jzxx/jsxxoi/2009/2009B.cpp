/*1764: 【基础】处理数
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 538解决 : 460
题目描述
给出一个正整数n，然后对n进行一系列处理，处理用以下代码表示：
０　　不做任何处理
１　　对原数加上１００,　若加上１００后大于１０００,则再减去１０００.
２　　对原数减去１００,　若减去１００后小于０,则再加上２００
３　　对原数除２取整
４　　对原数乘４,若乘４之后大于１０００,则除以１０００取余数。
问 题：输入n，k后，将 n作为原数（1≤ n ＜ 1000）， k为处理码的十进制表示（1＜k≤30000）。要求将k化为五进制的数，然后以该五进制数从高位到低位的顺序，分别将每位数字作为处理码对原数按上述规则进行处理，求处理后的结果。
 
输入
n k （２个整数）
 
输出
处理后的结果
 
样例输入 [复制]
33 247
样例输出 [复制]
28
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2009年江苏省小学生信息学（计算机）奥赛*/
//
// Created by Hz Yang on 2017/6/19.
//
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;
int n, k;
stack<int> st;

void i25(int x) {
    while (x > 0) {
        st.push(x % 5);
        x /= 5;
    }
}

void check(int x) {
    switch (x) {
        case 0:
            return;
        case 1: {
            n += 100;
            if (n > 1000) n -= 1000;
            return;
        }
        case 2: {
            n -= 100;
            if (n < 0) n += 200;
            return;
        }
        case 3:
            n /= 2;
            return;
        case 4: {
            n *= 4;
            n %= 1000;
        }
    }
}

void work() {
    while (st.size() > 0) {
        check(st.top());
        st.pop();
    }
}

int main() {
    cin >> n >> k;
    i25(k);
    work();
    cout << n;
    return 0;
}
