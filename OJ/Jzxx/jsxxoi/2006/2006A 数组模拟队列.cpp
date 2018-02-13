//
// Created by Hz Yang on 2017/6/15.
//
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n,m,a[10010]={0};
    cin >> n >> m;
    int s=1,g=n+1;
    for (int i = 1; i <= n; ++i) {
        a[i]=i;
    }
    while(s!=g){
        for (int i = 1; i < m; ++i) {
            a[g++]=a[s++];
        }
        s++;
    }
    cout<<a[s-1]<<endl;
    return 0;
}


