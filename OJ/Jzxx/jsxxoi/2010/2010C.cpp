/*1805: 【基础】印度国王的棋盘
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 854解决 : 470
题目描述
印度国王使用的棋盘有N*N个格子（N 无限大）。现在从第一个格子开始放麦粒,第一个格子放1 粒、第二个格子放2粒、第三个格子放4粒，第N个格子放2^(N-1)粒麦粒。请你编程计算从第K格至第M 格共有多少粒麦粒。
 
输入
K M （ 4 <= K＜M <=100）。
 
输出
共有多少粒麦粒。（结果不超过6位时，直接输出结果；结果超过6位时，只输出结果的最高3位和最低3位，以逗号分隔）。
 
样例输入
样例1: [复制]
4 5
样例2: [复制]
4 98
样例输出
样例1: [复制]
24
样例2: [复制]
316,336
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2010年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/8.
//
#include <cstdio>
#include <iostream>

using namespace std;

int k, m, a[10005], b[10005], lena, lenb, i, j;

int main() {
    cin >> k >> m;
    a[1] = 1;
    lena = 1;
    b[1] = 0;
    lenb = 1;
    if (k == 1) b[1] = 1;
    for (i = 2; i <= m; ++i) {//第一个格子是1,而2的1次方是2，所以i从2开始，这样可以少算1次
        for (j = 1; j <= lena; ++j) {//计算2的n次方
            a[j] *= 2;
            if (i >= k) b[j] += a[j];//从2的k次方开始累加
        }
        for (j = 1; j <= lena; ++j) {//
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
        }
        for (j = 1; j <= lenb; ++j) {//高精度加法
            b[j + 1] += b[j] / 10;
            b[j] %= 10;
        }
        while (a[lena + 1] > 0) {
            lena++;
            a[lena + 1] += a[lena] / 10;
            a[lena] %= 10;
        }
        while (b[lenb + 1] > 0) {
            lenb++;
            b[lenb + 1] += b[lenb] / 10;
            b[lenb] %= 10;
        }
    }
    if (lenb <= 6) {
        for (i = lenb; i >= 1; i--) printf("%d", b[i]);
    } else {
        printf("%d%d%d,%d%d%d", b[lenb], b[lenb - 1], b[lenb - 2], b[3], b[2], b[1]);
    }
    return 0;
}

