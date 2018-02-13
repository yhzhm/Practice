//
// Created by Hz Yang on 2017/5/8.
//
//超时
#include <iostream>
#include <cmath>

using namespace std;

bool check(int n) {
    int x = sqrt(n);
    if (n == x * x) return true;
    else return false;
}

int main() {
    int n, k, beg, end, sum = 0, count = 0;
    cin >> n >> k;
    for (int i = 0; i < n-k; ++i) {
        for (int j = 1; j <=k ; ++j) {
            sum+=i+j;
        }
        if (check(sum)) count++;
        sum = 0;
    }
    cout << count << endl;
    return 0;
}
