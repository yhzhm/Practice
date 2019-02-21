// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
int f[60010][60010];
int main()
{
    int n; cin >> n;
    for (int j = 0; j <= n + 1; ++j) f[0][j] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            f[i][j] = f[i - 1][j + 1] + f[i][j - 1];
        }
    }
    cout << f[n][0] << endl;
    return 0;
}