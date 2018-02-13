/*描述
给定一个5*5的矩阵，每行只有一个最大值，每列只有一个最小值，寻找这个矩阵的鞍点。
鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。
例如：在下面的例子中（第4行第1列的元素就是鞍点，值为8 ）。
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8 6 4 7 2
15 10 11 20 25

输入
输入包含一个5行5列的矩阵
输出
如果存在鞍点，输出鞍点所在的行、列及其值，如果不存在，输出"not found"
样例输入
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8  6 4 7 2
15 10 11 20 25
样例输出
4 1 8*/
//
// Created by Hz Yang on 2017/5/6.
//用二维数组，0行存储max值，1行存储对应坐标
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int a[6][6], max[2][6], min[2][6];
    memset(max, 0x80, sizeof(max));
    memset(min, 0x7f, sizeof(min));
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cin >> a[i][j];
            if (max[0][i] < a[i][j]) max[0][i] = a[i][j], max[1][i] = j;
            if (min[0][j] > a[i][j]) min[0][j] = a[i][j], min[1][j] = i;
        }
    }
    for (int i = 1; i <= 5; ++i) {
        if (min[1][max[1][i]] == i) {
            cout << i << ' ' << max[1][i] << ' ' << max[0][i] << endl;
            return 0;
        }
    }
    cout << "not found" << endl;

    return 0;
}

