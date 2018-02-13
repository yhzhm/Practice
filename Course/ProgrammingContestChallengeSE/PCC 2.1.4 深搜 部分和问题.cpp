/*
 * 给定整数a1,a2,...,an，判断是否可以从中选出若干数，是它们的和恰好为k。
 */

//
// Created by Hz Yang on 2017/5/2.
//
#include <iostream>
using namespace std;
const int MAX_N=25;
int a[MAX_N];
int n,k;
bool dfs(int i,int sum)
{
    if(i==n) return sum==k;
    if (dfs(i+1,sum)) return true;
    if (dfs(i+1,sum+a[i])) return true;
    return false;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    if( dfs(0,0) ) printf("Yes\n");
    else printf("No\n");
    return 0;
}
