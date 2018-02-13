/*2874: 【基础】连续数的和
时间限制 : 1 Sec内存限制 : 128 Mb提交 : 191解决 : 70
题目描述
给出两个整数n和k，（2≤n≤70000,1≤k≤n），求出1,2,3,…,n中连续k个数的和，并计算出和为平方数的个数。
例如n=10,k=3。在1,2,…,10中，连续3个数的和有
1+2+3=6
2+3+4=9
3+4+5=12
4+5+6=15
5+6+7=18
6+7+8=21
7+8+9=24
8+9+10=27
其中和为平方数的仅有9，因为9=3×3。
输入
n,k两个整数。
输出
一个整数，即1,2,…,n中连续k个数的和为平方数的个数。
样例输入 [复制]
10 3
样例输出 [复制]
1*/
//
// Created by Hz Yang on 2017/5/8.
//
#include <iostream>
#include <cmath>

using namespace std;

bool check(int n) {
    int x = sqrt(n);
    if (n == x * x) return true;
    else return false;
}

int main() {
    int n, k, beg, sum = 0, count = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        sum += i;
    }
    beg = 1;
    for (int i = k; i <= n; ++i, ++beg) {
        if (check(sum)) count++;
        sum = sum + i + 1 - beg;
    }
    cout << count << endl;
    return 0;
}
