// Created by Hz Yang on 2019.04
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair<int, int> PII;
const int M = 2e6 + 10;
int n;
PII a[M];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
    sort(a, a + n);

    int j, res = 1, last = INT_MAX, dir = -1;
    for (int i = 0; i < n; i = j) {
        j = i;
        while (j < n && a[i].first == a[j].first) j++;

        int minp = a[i].second, maxp = a[j - 1].second;
        if (dir == -1) {
            if (last > maxp) last = minp;
            else dir = 1, last = maxp;
        } else {
            if (last < minp) last = maxp;
            else res++, dir = -1, last = minp;
        }
    }
    cout << res << endl;
    return 0;
}