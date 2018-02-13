/*输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。

输入
第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以一个空格分开。
接下来输入的m行数据中，每行包含n个整数，整数之间以一个空格分开。
输出
输出对应矩阵的边缘元素和
样例输入
3 3
3 4 1
3 7 1
2 0 1
样例输出
15*/

//
// Created by Hz Yang on 2017/4/25.
//
#include <iostream>

using namespace std;

int main() {
    int a[110][110], n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                sum += a[i][j];
        }
    }
    cout << sum;
    return 0;
}
