//
// Created by Hz Yang on 2017/6/8.
//
//用1个线性表存放H数，用四个变量构造H数
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;
LL n, m, h[4000];

int main() {
    cin >> n;
    n++;
    h[1] = 1;
    int t2 = 1, t3 = 1, t5 = 1, t7 = 1;
    for (int i = 2; i <= n; ++i) {
        m = min(min(h[t2] * 2, h[t3] * 3), min(h[t5] * 5, h[t7] * 7));
        h[i] = m;
        if (m == h[t2] * 2) t2++;
        if (m == h[t3] * 3) t3++;
        if (m == h[t5] * 5) t5++;
        if (m == h[t7] * 7) t7++;
    }
    cout << h[n];
    return 0;
}
