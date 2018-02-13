/*04:错误探测
描述
给定n*n由0和1组成的矩阵，如果矩阵的每一行和每一列的1的数量都是偶数，则认为符合条件。
你的任务就是检测矩阵是否符合条件，或者在仅改变一个矩阵元素的情况下能否符合条件。
"改变矩阵元素"的操作定义为0变成1或者1变成0。

输入
输入n + 1行，第1行为矩阵的大小n(0 < n < 100)，以下n行为矩阵的每一行的元素，元素之间以一个空格分开。
输出
如果矩阵符合条件，则输出OK；
如果矩阵仅改变一个矩阵元素就能符合条件，则输出需要改变的元素所在的行号和列号，以一个空格分开。
如果不符合以上两条，输出Corrupt。
样例输入
样例输入1
4
1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1

样例输入2
4
1 0 1 0
0 0 1 0
1 1 1 1
0 1 0 1

样例输入3
4
1 0 1 0
0 1 1 0
1 1 1 1
0 1 0 1
样例输出
样例输出1
OK

样例输出2
2 3

样例输出3
Corrupt*/
//
// Created by Hz Yang on 2017/5/6.
//用二维数组记录行列的和
#include <iostream>

using namespace std;

int main() {
    int n, x = 0, y = 0, countX = 0, countY = 0, a[105][105], b[105][105];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            b[i][1] += a[i][j];
            b[j][2] += a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i][1] % 2 != 0) countX++, x = i;
        if (b[i][2] % 2 != 0) countY++, y = i;
    }
    if (countX == 0 && countY == 0) cout << "OK" << endl;
    else if (countX == 1 && countY == 1) cout << x << ' ' << y << endl;
    else cout << "Corrupt" << endl;
    return 0;
}

