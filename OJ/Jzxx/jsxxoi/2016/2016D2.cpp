//
// Created by Hz Yang on 2017/5/3.
//
#include <iostream>

using namespace std;

int main() {
    int n, s, sum = 0, a[256] = {0};
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        s = s * 345 % 19997;
        a[97 + (s % 26)]++;
    }
    for (int i = 0; i < n; ++i) {
        s = s * 345 % 19997;
        a[97 + (s % 26)]--;
    }
    for (int i = 0; i < 256; i++) {
        if (a[i] > 0) sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
