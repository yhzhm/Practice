//
// Created by Hz Yang on 2017/5/6.
//用两个一维数组，h[]存储行最大值的列坐标，z[]存储列最小值的行坐标
#include <iostream>
using namespace std;

int main() {
    int a[6][6], h[6], z[6];
    for (int i = 1; i <= 5; ++i) {
        h[i] = 1;
        z[i] = 1;
    }
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cin >> a[i][j];
            if (a[i][h[i]] < a[i][j]) h[i] = j;
            if (a[z[j]][j] > a[i][j]) z[j] = i;
        }
    }
    for (int i = 1; i <= 5; ++i) {
        if (z[h[i]] == i) {
            cout << i << ' ' << h[i] << ' ' << a[i][h[i]] << endl;
            return 0;
        }
    }
    cout << "not found" << endl;

    return 0;
}
