//
// Created by Hz Yang on 2017/6/7.
//
//用4个线性表分别存放Ｈ数表的2倍表、3倍表、5倍表和7倍表，然后利用这4个表来生成Ｈ数表。
//n最大为4220 第4220个H数为306307575

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;
//h[]保存h数，h2[],h3[],h5[],h7[]构造h数
LL n, m, h[4000], h2[4000], h3[4000], h5[4000], h7[4000];

int main() {
    cin >> n;
    h[1] = 1;
    h2[1] = 2;
    h3[1] = 3;
    h5[1] = 5;
    h7[1] = 7;
    int t2 = 1, t3 = 1, t5 = 1, t7 = 1;
    for (int i = 2; i <= n+1; ++i) {
        m = min(min(h2[t2], h3[t3]), min(h5[t5],h7[t7]));
        h[i] = m;
        h2[i] = m * 2;
        h3[i] = m * 3;
        h5[i] = m * 5;
        h7[i] = m * 7;
        if (h2[t2] == m) t2++;
        if (h3[t3] == m) t3++;
        if (h5[t5] == m) t5++;
        if (h7[t7] == m) t7++;
    }
    cout<<h[n+1];
    return 0;
}
