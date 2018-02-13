//
// Created by Hz Yang on 2017/6/9.
// dfs()中，if(c<k)优化
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
int n, k, c, count, a[25];

void check(int num) {
    int i = 0, x, sum = 0;
    x = num;
    while (x > 0) {
        ++i;
        x /= 10;
    }
    x = num;
    while (x > 0) {
        sum += pow((x % 10), i);
        x /= 10;
    }
    if (sum == num) count++;
    return;
}

void dfs(int p, int sum) {
    if (p > n ) {
        if(c==k){
            check(sum);
        }
        return;
    }
    dfs(p + 1, sum);
    if (c < k) {
        c++;
        dfs(p + 1, sum + a[p]);
        c--;
    }

}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << count;
    return 0;
}
