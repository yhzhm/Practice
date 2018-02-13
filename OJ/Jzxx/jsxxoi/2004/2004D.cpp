/*1279: 【基础】求长度为素数的路径个数
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 486解决 : 346
题目描述
对于正整数n （3≤n≤13），可以画出n阶的回形矩阵。下面画出的分别是3阶的，4阶的和7阶的回形矩阵：
 
对于n阶回形矩阵，从左上角出发，每步可以向右或向下走一格，走2*n-2步，可以到达右下角。我们把这样的路径上所有格子中的数值之和，叫做该路径的长度。本题要求，对于给出n值，求出n阶回形矩阵有多少路径的长度为素数？ 如n=3时，路径及长度有：
 
因此说，3阶回形矩阵有2条路径的长度为素数。
 
输入
一个自然数n （3≤n≤13，不必判错）。
 
输出
一个正整数，即n阶回形矩阵中长度为素数的路径的个数。
 
样例输入 [复制]
3
样例输出 [复制]
2
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
江苏省青少年信息学奥林匹克竞赛（JSOI2004）小学组复赛*/

//
// Created by Hz Yang on 2017/6/14.
//
#include <cstdio>
#include <iostream>

using namespace std;

int n, a[15][15], s, cnt;

bool isp(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void dfs(int x, int y) {
    s += a[x][y];
    if (x == n && y == n) cnt += isp(s);
    if (x + 1 <= n) dfs(x + 1, y);
    if (y + 1 <= n) dfs(x, y + 1);
    s -= a[x][y];
}

//void dfs(int x, int y) {
//    if (0 < x && x <= n && 0 < y && y <= n) {
//        s += a[x][y];
//        if (x == n && y == n) cnt += isp(s);
//        dfs(x + 1, y);
//        dfs(x, y + 1);
//        s -= a[x][y];
//    }
//}

int main() {
    cin >> n;
    int z = n / 2 + n % 2, x = 1, y = 1, nx = n, ny = n;
    for (int i = 1; i <= z; ++i) {
        for (int j = x; j <= ny; ++j) {
            a[x][j] = i;
        }
        for (int k = x; k <= nx; ++k) {
            a[k][ny] = i;
        }
        for (int j = ny; j >= y; --j) {
            a[nx][j] = i;
        }
        for (int k = nx; k >= x; --k) {
            a[k][y] = i;
        }
        x++;
        y++;
        nx--;
        ny--;
    }
    dfs(1, 1);
    cout << cnt;
//    for (int i = 1; i <= n ; ++i) {
//        for (int j = 1; j <=n ; ++j) {
//            cout<<a[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    return 0;
}
