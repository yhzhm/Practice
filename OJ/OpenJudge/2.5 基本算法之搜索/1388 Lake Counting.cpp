/*1388:Lake Counting
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors.

Given a diagram of Farmer John's field, determine how many ponds he has.
输入
* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.
输出
* Line 1: The number of ponds in Farmer John's field.
样例输入
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
样例输出
3
提示
OUTPUT DETAILS:

There are three ponds: one in the upper left, one in the lower left,and one along the right side.
来源
USACO 2004 November*/

//
// Created by Hz Yang on 2017/6/7.
//
#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
char a[105][105];

void dfs(int x, int y) {
    a[x][y] = '.';
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx, ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == 'W') dfs(nx, ny);
        }
    }
    return;
}

int main() {
    int res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res;
    return 0;
}
