//
// Created by Hz Yang on 2017/6/7.
// 乘法没有用高精度，超范围
#include <iostream>

using namespace std;

int main() {
    long long  n,i,j,sum=0,x=0;
    cin >> n;
    for ( i = 2; i < n; ++i ) {
        sum+=i;
        if(sum>=n) break;
    }
    if(sum>n) x=sum-n;
    sum=1;
    for (j = 2; j <= i ; ++j) {
        if(j==x) continue;
        sum*=j;
    }
    x=sum;sum=0;
    while(x>0){
        sum+=x%10;
        x/=10;
    }
    cout << sum;
    return 0;
}
