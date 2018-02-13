//
// Created by Hz Yang on 2017/6/17.
//
/*
分析：相当于背包容量和背包中物品价值二者相等的一般背包问题。（也称为伪背包问题）
对于每一个物品i，都存在放入箱子和不放入箱子两种情况。当前箱子容量剩余j时，若i放入，则为dp[j-a[i]]+a[i])；
若i不放入，则为dp[i]；因此，状态转移方程为：dp[j] = max(dp[j], dp[j-a[i]]+a[i])。*/
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, i, j, a[105], sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int v = sum / 2;
    int s[v + 1];
    memset(s,0, sizeof(s));
    for (i = 0; i < n; ++i) {
        for (j = v; j >= a[i]; --j) {
            s[j] = max(s[j], s[j - a[i]] + a[i]);
        }
    }
    cout << sum - s[v];
    return 0;
}


