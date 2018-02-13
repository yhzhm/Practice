/*描述
输入两个n行m列的矩阵A和B，输出它们的和A+B。

输入
第一行包含两个整数n和m，表示矩阵的行数和列数。1 <= n <= 100，1 <= m <= 100。
接下来n行，每行m个整数，表示矩阵A的元素。
接下来n行，每行m个整数，表示矩阵B的元素。
相邻两个整数之间用单个空格隔开，每个元素均在1~1000之间。
输出
n行，每行m个整数，表示矩阵加法的结果。相邻两个整数之间用单个空格隔开。
样例输入
3 3
1 2 3
1 2 3
1 2 3
1 2 3
4 5 6
7 8 9
样例输出
2 4 6
5 7 9
8 10 12*/

//
// Created by Hz Yang on 2017/5/6.
//循环3可以和循环2合并
#include <iostream>
using namespace std;

int main() {
    int n, m, a[105][105], b[105][105];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> b[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << a[i][j] + b[i][j] << ' ';
        cout << endl;
    }
    return 0;
}


