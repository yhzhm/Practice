/*1804: 【入门】因子求和
时间限制:1 Sec内存限制:64 Mb提交:2510解决:1145
题目描述
已知一个正整数N（20 <= N <= 800000000），请你编写程序求出该数的全部因子（不包括1）的和。

输入
N

输出
一个整数（因子和）

样例输入 [复制]
24
样例输出 [复制]
35
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2010年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/8.
//
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n,i,sum=0;
    cin >> n;
    for(i=2;i*i<=n;++i){
        if(n%i==0) sum+=i+n/i;
    }
    if(i*i==n) sum-=i;
    cout << sum;
    return 0;
}
