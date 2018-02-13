//
// Created by Hz Yang on 2017/6/7.
// 因为边界元素值为0，所以可以保证不越界
#include <iostream>

using namespace std;
int n, m, s, sum = 0, a[105][105];
int maxi = ~((unsigned) (-1) >> 1);
//int mini = 0x7fffffff;
//int maxi = 0x80000000;

void dfs(int i, int j) {
    sum += a[i][j];
    maxi = maxi > sum ? maxi : sum;
    if (a[i + 1][j] > a[i][j]) dfs(i + 1, j);
    if (a[i][j + 1] > a[i][j]) dfs(i, j + 1);
    if (a[i - 1][j] > a[i][j]) dfs(i - 1, j);
    if (a[i][j - 1] > a[i][j]) dfs(i, j - 1);
    sum -= a[i][j];
}


int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s = s * 345 % 19997;
            a[i][j] = (s % 10) + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dfs(i, j);
        }
    }
    cout << maxi << endl;
    return 0;
}

