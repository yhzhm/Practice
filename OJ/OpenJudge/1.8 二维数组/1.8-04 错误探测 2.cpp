//
// Created by Hz Yang on 2017/5/6.
//用两个一维数组分别记录行和列的和
#include <iostream>

using namespace std;

int main() {
    int n, x = 0, y = 0, countX = 0, countY = 0, a[105][105], h[105], v[105];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            h[i] += a[i][j];
            v[j] += a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (h[i] % 2 != 0) countX++, x = i;
        if (v[i] % 2 != 0) countY++, y = i;
    }
    if (countX == 0 && countY == 0) cout << "OK" << endl;
    else if (countX == 1 && countY == 1) cout << x << ' ' << y << endl;
    else cout << "Corrupt" << endl;
    return 0;
}

