/*1276: 【基础】蛇形矩阵
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 460解决 : 223
题目描述
从键盘输入正整数n，i和j ，(1<=i,j<= n <=20)，然后计算并显示n阶蛇形矩阵的第i行第j列元素的值 （下图给出的是7阶蛇形矩阵）。
 
 
输入
一行，为三个正整数n i j。表示要计算并显示n阶蛇形矩阵的第i行第j列的元素值。
 
输出
一行，只有一个正整数，即根据对应的输入数据计算出的元素值。
 
样例输入 [复制]
7 3 5
样例输出 [复制]
3
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2004江苏省青少年信息学奥林匹克复赛*/

//
// Created by Hz Yang on 2017/6/14.
// 生成右上角半个矩阵（包括对角线），左下角半个矩阵通过计算得到
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n, a, b, c[25][25];
    cin >> n >> a >> b;
    int dx[] = {1, -1};//两个“行走”方向
    int dy[] = {1, -1};
    int x = 0, y = n - 1, nx, ny, i, k = 1;
    for (i = 1; i <= n * n; ++i) {
        c[x][y] = i % 10;
        c[n - x - 1][n - y - 1] = (n * n - i + 1) % 10;//左下角对应矩阵元素
        nx = x + dx[k];//模拟行走，计算下一个元素位置
        ny = y + dy[k];
        //对计算得到的下一个元素位置进行判断
        if ((n % 2 == 1) && (nx < 0 && ny < 0)) break;//n奇数矩阵，对角线完成
        if ((n % 2 == 0) && (nx == n && ny == n)) break;//n偶数矩阵，对角线完成
        if (nx < 0) {//向上越界
            nx++;//调整
            k = (k + 1) % 2;//转向
        }
        else if (ny == n) {//向下越界
            ny--;//调整
            k = (k + 1) % 2;//转向
        }
        x = nx;//计算，判断，调整后，正确的下一个元素位置。
        y = ny;
    }
//    for (int j = 0; j < n; ++j) {
//        for (int l = 0; l < n; ++l) {
//            printf("%4d",c[j][l]);
//        }
//        cout<<endl;
//    }
    cout << c[a - 1][b - 1] << endl;
    return 0;
}
