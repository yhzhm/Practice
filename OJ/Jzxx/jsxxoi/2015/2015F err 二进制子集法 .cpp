//
// Created by Hz Yang on 2017/5/16.
//二进制子集法 因为超过int范围才错误，但方法值得介绍
#include <iostream>

using namespace std;
int n, k, a[105];

int check(int comb) {
    int mind = 0x7fffffff;
    int i, beg, d;
    for (i = 0; i < k; ++i) {
        if ((1 << i) & comb) {
            beg = a[i];
            break;
        }
    }
    for (i++; i < k; ++i) {
        if ((1 << i) & comb) {
            d = a[i] - beg;
            mind = min(d, mind);
            beg = a[i];
        }
    }
    return mind;
}

int main() {
    cin >> n >> k >> a[0];
    for (int i = 1; i < k; ++i) {
        a[i] = a[i - 1] + ((a[i - 1] * 2357 + 137) % 10) + 1;
    }
    int x, y, d, maxd = 0;
    int comb = (1 << n) - 1;
    while (comb < 1 << k) {
        x = comb & -comb;
        y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
        d = check(comb);
        maxd = max(d, maxd);
    }
    cout << maxd << endl;
    return 0;
}
