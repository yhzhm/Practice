/*1807: 【基础】螺旋方阵
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 900解决 : 711
题目描述
输入一个正整数N（1 <= N <=20）后，可以得到一个N*N的数字螺旋方阵，分别求该方阵中 的主对角线与副对角线上的数字之和S，P，输出S、P的差。 例如：N=5 得到的数字螺旋方阵如下：
           1    2   3    4    5          其中：主对角线从左上角到右下角，得到
           16  17   18  19   6               的数字之和为：S=1+17+25+21+9=73
           15   24  25  20   7               副对角线从右上角到左下角，得到
           14   23  22  21   8               的数字之和：P=5+19+25+23+13=85
           13   12  11  10   9         S-P= - 12
 
输入
一个正整数N
 
输出
主对角线与副对角线上的数字之和的差。
 
样例输入 [复制]
5
样例输出 [复制]
-12
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2010年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/9.
//
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n, a[25][25] = {0};
    cin >> n;
    //每条边的下标，在x，y上的增量，或者说四个移动方向中x，y的变化值
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int x = 0, y = 0, nx, ny, i, k = 0, sum1 = 0, sum2 = 0;//k用来表示边，k=0,1,2,3 分别代表上右下左

    for (i = 1; i <= n * n; ++i) {
        a[x][y] = i;
        if (x - y == 0) sum1 += a[x][y]; //矩阵坐标从0开始
        if (x + y == n-1) sum2 += a[x][y];
        nx = x + dx[k];//下一个坐标位置
        ny = y + dy[k];
        if (nx < 0 || nx == n || ny < 0 || ny == n || a[nx][ny] != 0) {//越界，或者已经赋值，转向
            k = (k + 1) % 4;
            nx = x + dx[k];
            ny = y + dy[k];
        }
        x = nx;
        y = ny;
    }
//    for (int j = 0; j < n; ++j) {  //打印矩阵
//        for (int l = 0; l < n; ++l) {
//            printf("%3d", a[j][l]);
//        }
//        printf("\n");
//    }
    cout << sum1 - sum2;
    return 0;
}

