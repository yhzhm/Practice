//
// Created by Hz Yang on 2017/5/6.
//
#include <iostream>
using namespace std;

int main() {
    int n,m,a[105][105],b[105][105];
    cin >> n >> m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin >> a[i][j];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin >> b[i][j];
            cout << a[i][j]+b[i][j]<<' ';
        }
        cout<< endl;
    }
    return 0;
}
