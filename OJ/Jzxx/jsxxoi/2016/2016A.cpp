/*题目描述
小明写出了一个数列，第 i 项 ai 的值为 i2。数列从第一项(i = 1)开始如下:
1, 4, 9, 16, 25, ...
编程求出这个数列前 n 项的和。
 
输入
整数n (1≤n≤1,000)
 
输出
一个整数:a1 +a2 +⋯+an的值。
 
样例输入
样例1: [复制]
6
样例2: [复制]
987
样例输出
样例1: [复制]
91
样例2: [复制]
320988850*/
//
// Created by Hz Yang on 2017/5/3.
//
#include <iostream>
using namespace std;

int main() {
    int n,sum=0;
    cin >> n;
    for (int i = 1; i <= n ; ++i) {
        sum+=i*i;
    }
    cout << sum;
    return 0;
}
