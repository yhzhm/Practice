//
// Created by Hz Yang on 2017/5/24.
//用数组b，统计选票
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n, a[1005], b[1005] = {0}, m = 0, pos = 0;
    cin >> n >> a[1];
    b[a[1]]++;
    for (int i = 2; i <= n; i++) {
        a[i] = (a[i - 1] * 37 + 33031) % n + 1;
        b[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (m < b[i]) {
            m = b[i];
            pos = i;
        }
    }

    cout << pos << endl;
    return 0;
}

