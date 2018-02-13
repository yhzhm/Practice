//
// Created by Hz Yang on 2017/6/14.
//
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
int p, n, m, a[45][45];

void dfs(int i, int j) {
    if (0 < i && i <= n && 0 < j && j <= n) {
        if (a[i][j] == 0) {
            a[i][j] = 2;
            p++;
            if (i == n && j == n) {m = min(p, m);return;}
            dfs(i + 1, j);
            dfs(i, j + 1);
            dfs(i - 1, j);
            dfs(i, j - 1);
            p--;
            a[i][j] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    m = n * n;
    dfs(1, 1);
    cout << n*n-m;
    return 0;
}

