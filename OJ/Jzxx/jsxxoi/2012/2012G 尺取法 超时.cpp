//
// Created by Hz Yang on 2017/6/2.
// 尺取法 超时
#include <iostream>

using namespace std;

int main() {
    unsigned long long n, i, j, sum = 0, count = 0;
    cin >> n;
    i = n / 2 + 1;
    sum += i;
    j = i - 1;
    for (;;) {
        while (j > 0 && sum < n) {
            sum += j--;
        }
        if (sum < n) break;
        else if (sum > n) sum -= i--;
        else {
            count++;
            sum -= i--;
        }
    }
    cout << count << endl;
    return 0;
}

