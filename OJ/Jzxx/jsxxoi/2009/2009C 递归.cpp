//
// Created by Hz Yang on 2017/6/14.
//

#include <cstdio>
#include <iostream>

using namespace std;

int cnt;

void palindrome(long long n) {
    long long x = n,s=0;
    while (x > 0) {
        s = s * 10 + x % 10;
        x /= 10;
    }
    if(s == n) return ;
    else {
        cnt++;
        palindrome(n+s);
    }
}

int main() {
    int n;
    cin >> n;
    palindrome(n);
    cout << cnt;
    return 0;
}

