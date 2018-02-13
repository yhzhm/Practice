//
// Created by Hz Yang on 2017/6/15.
// 将拆分转换成string，再判断是否是回文
#include <cstdio>
#include <iostream>
using namespace std;
int n,cnt,a[30];
string i2s(int *a)
{
    string s;
    char x;
    for (int i = 1; i <30 ; ++i) {
        if(a[i]) {
            x=a[i]+48;
            s=s+x;
        }
    }
    return s;
}
bool palindrome(string s)//回文字符串
{
    string::size_type i;
    for (i = 0; i < s.size() >> 1; ++i) {
        if (s[i] != s[s.size() - i - 1]) return 0;
    }
    return 1;
}

void dfs(int p,int n)
{
    if(n==0) {cnt+=palindrome(i2s(a));return;}
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


