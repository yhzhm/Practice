//
// Created by Hz Yang on 2017/5/16.
// 用string判断
#include <iostream>
#include <string>

using namespace std;

bool check(int n) {
    if (n >= 1 && n <= 9) return true;
    string s = to_string(n);
    int mid = s.size() >> 1;
    for (int i = 0; i <= mid; ++i) {
        if (s[i] != s[s.size() - 1 - i])return false;
    }
    return true;
}

int main() {
    int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (check(i)) count++;
    }
    cout << count << endl;
    return 0;
}
