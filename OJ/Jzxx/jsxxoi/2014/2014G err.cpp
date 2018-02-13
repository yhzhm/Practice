//
// Created by Hz Yang on 2017/5/24.
//Segmentation fault:段错误，检查是否有数组越界，指针异常，访问到不应该访问的内存区域
#include <iostream>

using namespace std;

bool a[1000000000 + 10];

int main() {
    int n;
    long long sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j % i == 0) a[j] = !a[j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i]) sum += i;
    }
    cout << sum << endl;
    return 0;
}
