//
// Created by Hz Yang on 2017/6/16.
// 能过省赛测试数据，oj40%超时
#include <cstdio>
#include <iostream>
using namespace std;
int n,a[105],sum,maxv,s,m;
void dfs(int p)
{
    if(p>n)  return;
    for (int i = 1; i >= 0 ; --i) {
        s+=a[p]*i;
        if(s<=m){
            if(s>maxv) maxv=s;
            if(s==m){
                if(sum%2==1)  maxv=m+1;
                return ;
            }
            dfs(p+1);
        }
        s-=a[p]*i;
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    m=sum/2;
    dfs(1);
    printf("%d",maxv);
    return 0;
}


