//
// Created by Hz Yang on 2017/6/15.
//
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n,m,a[10010]={0},cnt=0;
    cin >> n >> m;
    int s=0,g=n+1;
    while(cnt<n-1){
        for (int i = 1; i < m; ++i) {
            while(a[s]) {
                s++;
                s%=n;
            }
            s++;
            s%=n;
            while(a[s]) {
                s++;
                s%=n;
            }
        }
        a[s]=1;
//        for (int j = 0; j < n; ++j) {
//            cout<<a[j]<<' ';
//        }
//        cout<<endl;
        cnt++;
    }
    while(a[s]) {
        s++;
        s%=n;
    }
//    for (int j = 0; j < n; ++j) {
//        cout<<a[j]<<' ';
//    }
    cout<<s+1<<endl;
    return 0;
}


