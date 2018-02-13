//
// Created by Yhz on 2017/5/31.
//超时
#include <iostream>
#include <cmath>
using namespace std;

bool check(long long  n)
{
    long long  x=n,i=0;
    while(x>0){
        i++;
        x/=10;
    }
    return (6*pow(10,i-1)+n/10)==4*n;
}
int main() {
    int  count=0;
    for (long long  i = 16;count<=2; i=i+2) {
        if(i%10==6 && check(i)) {
            cout<<i<<' ';
            count++;
        }
    }
    return 0;
}
