/*1721: 【基础】整数的拼接
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 869解决 : 283
题目描述
设有n个整数(3≤n≤10)，将这些整数拼接起来，可以形成一个最大的整数。 例如 n=3, 三个整数分别为21, 7, 34， 拼接后最大的整数为： 73421
 
输入
第一行一个整数n ，表示有n 个整数 第二行n个整数，数与数之间用一个空格分隔。
 
输出
一个拼接后的最大的整数。
 
样例输入 [复制]
3
21 7 34
样例输出 [复制]
73421
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2006年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/17.
// 如果用next_permutation有10%超时，这里加双重循环进行微调
// 5
// 3 33 331 332 334
// 334 33 3 332 331

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s[11],s2;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    sort(s,s+n);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j <n ; ++j) {
            if(s[i]+s[j]>s[j]+s[i]) swap(s[i],s[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        s2=s[i]+s2;
    }
    cout<<s2;
    return 0;
}
