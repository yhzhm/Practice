/*
输入	13，4	22，6	73，4	70，5	43，8	77，4	23，3	37，9	44，10	32，10
输出	18	    136	    2808	9542	5066	3289	44	    2194	6912	807*/


//
// Created by Hz Yang on 2017/6/13.
// 8%WA,怀疑是数据超精度范围
#include<iostream>

using namespace std;
unsigned long long a[11111][15];

unsigned long long p(int n, int k) {
    if (n < k) return 0;
    if (k == 1)return 1;
    if (k == n)return 1;
    if (a[n][k] > 0) return a[n][k];
    else a[n][k] = p(n - 1, k - 1) + p(n - k, k);
    return a[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << p(n, k) << endl;
    return 0;
}
