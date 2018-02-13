//
// Created by Hz Yang on 2017/8/23.
//
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    map<string, int> cnt;
    string x, s[15];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> x >> a >> b;
        if (b == 0) cnt[x] -= a;
        else {
            cnt[x] += a % b - a;
            for (int j = 0; j < b; ++j) {
                string y;
                cin >> y;
                cnt[y] += a / b;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << s[i] << ' ' << cnt[s[i]] << endl;
    }

    return 0;
}

