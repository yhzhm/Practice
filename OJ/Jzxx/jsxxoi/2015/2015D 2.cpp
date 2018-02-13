//
// Created by Hz Yang on 2017/5/8.
// 改变了累加sum的方式
#include <iostream>
#include <cmath>

using namespace std;

bool check(int n) {
    int x = sqrt(n);
    if (n == x * x) return true;
    else return false;
}

int main() {
    int n, k, beg = 0, sum = 0, count = 0;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        sum += i;
    }
    for (int i = k; i <= n; ++i, ++beg) {
        sum = sum + i - beg;
        if (check(sum)) count++;
    }
    cout << count << endl;
    return 0;
}
