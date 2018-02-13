//
// Created by Hz Yang on 2017/5/13.
// 用辅助数组b记录转置
#include <iostream>

using namespace std;

int main() {
    int n, m, a[105][105], b[105][105];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
