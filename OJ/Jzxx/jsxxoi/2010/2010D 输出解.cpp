//
// Created by Hz Yang on 2017/6/9.
//
#include <cstdio>
#include <iostream>

using namespace std;
int n,k,c,a[15];
void dfs(int p,int b,int e)
{
    int i;
    if(p==k) {
        a[p]=e;
        printf("%d=%d",n,a[1]);
        for (i = 2; i <=p ; ++i) {
            printf("+%d",a[i]);
        }
        printf("\n");
        c++;
        return;}
    for ( i = b;  i <= e ; ++i) {
        a[p]=i;
        if(i<=e-i) dfs(p+1,i,e-i);
    }

}
int main() {
    cin >> n >> k;
    dfs(1,1,n);
    cout << c;
    return 0;
}

