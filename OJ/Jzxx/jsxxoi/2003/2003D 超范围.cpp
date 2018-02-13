//
// Created by Hz Yang on 2017/6/15.
// 用整数判断回文数，超范围
#include <cstdio>
#include <iostream>
using namespace std;
int n,cnt,a[30];
bool palindrome(int *a)
{
    unsigned long long  s1=0,s2=0,x=0;
    for (int i = 1; i <30 ; ++i) {
        if(a[i]) {cout<<a[i]<<' ';s1=s1*10+a[i];}
    }
    cout<<s1<<endl;
    x=s1;
    while(x>0){
        s2=s2*10+x%10;
        x/=10;
    }
    return s1==s2;
}
void dfs(int p,int n)
{
    if(n==0) {cnt+=palindrome(a);return;}
    for (int i = 1; i <=n ; ++i) {
        a[p]=i;
        dfs(p+1,n-i);
        a[p]=0;
    }
}
int main() {
    cin >> n;
    dfs(1,n);
    cout<< cnt-1;
    return 0;
}


