/*描述
输入一个n行m列的矩阵A，输出它的转置AT。
输入
第一行包含两个整数n和m，表示矩阵A的行数和列数。1 <= n <= 100，1 <= m <= 100。
接下来n行，每行m个整数，表示矩阵A的元素。相邻两个整数之间用单个空格隔开，每个元素均在1~1000之间。
输出
m行，每行n个整数，为矩阵A的转置。相邻两个整数之间用单个空格隔开。
样例输入
3 3
1 2 3
4 5 6
7 8 9
样例输出
1 4 7
2 5 8
3 6 9*/
//
// Created by Hz Yang on 2017/5/13.
// 输入时直接转置
#include <iostream>
using namespace std;

int main() {
    int n,m,a[105][105];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m ; ++j) {
            cin>>a[j][i];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n ; ++j) {
            cout<<a[i][j]<<' ';
        }
        cout << endl;
    }
    return 0;
}
