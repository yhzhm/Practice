//
// Created by Hz Yang on 2017/6/6.
//
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
bool isPrime(int n)
{
    if(n<2) return false;
    for (int i = 2; i*i <= n; ++i) {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n,j=0,a[10000],x,sum=0;
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        if(isPrime(i)) {
//            ++j;
            x=++j+i;
            if(isPrime(x)) sum+=x;
        }

    }
    cout<<sum%(n+1)<<endl;
    return 0;
}
