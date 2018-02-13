//
// Created by Hz Yang on 2017/6/16.
// 同样超时
#include <cstdio>
#include <iostream>
using namespace std;
int n,a[105],sum,minv,x,y,s,m;
void dfs(int p)
{
    if(p>n) {
        x=s;
        y=sum-s;
        if(x<y) swap(x,y);
        if(x-y<minv){minv=x-y;m=x;}
        return;
    }
    for (int i = 1; i >= 0 ; --i) {
        s+=a[p]*i;
        dfs(p+1);
        s-=a[p]*i;
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        sum+=a[i];
    }
    minv=sum;
    dfs(1);
    cout<<m;
    return 0;
}


