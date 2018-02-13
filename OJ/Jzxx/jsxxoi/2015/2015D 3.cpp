//
// Created by Hz Yang on 2017/6/5.
//
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

bool check(int n) {
    int x = sqrt(n);
    return x * x == n;
}

int main() {
    int n, k, count = 0;
    cin >> n >> k;
    int sum = (1 + k) * k / 2;
    if (check(sum)) count++;
    for (int i = 2; i <= n - k + 1; i++) {
        sum += k;
        if (check(sum)) count++;
    }
    cout << count;
    return 0;
}
