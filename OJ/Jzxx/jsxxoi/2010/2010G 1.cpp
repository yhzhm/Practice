/*1809: 【提高】水仙花数
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 876解决 : 353
题目描述
若一个长度为 X正整数，其各位上数字的X次方的和等于其自己，则称该数为水仙花数。例如：153 的长度X=3，且153 = 13+53+33 所以, 153 是水仙花数。现有N 个正整数（10 <= N <= 20），要求从这N个数中任取K个（ 2 <=K <=6），并求出这K个数的和，统计和为水仙花数的个数。
 
输入
第一行是二个整数N K，第二行是N个正整数（每个数均在大于等于10 、小于等于1000 之间）。
 
输出
一个整数，即满足条件的水仙花数的个数。
 
样例输入 [复制]
4 3
40 100 13 27
样例输出 [复制]
1
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2010年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/9.
// 用01背包法取子集，再判断是否是水仙花数
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
int n, k, c, count, a[25], b[25];

void check(int num) {
    int i = 0, x, sum = 0;
    x = num;
    while (x > 0) {
        ++i;
        x /= 10;
    }
    x = num;
    while (x > 0) {
        sum += pow((x % 10), i);
        x /= 10;
    }
    if (sum == num) count++;
    return;
}

void dfs(int p, int c, int sum) {
    if (p > n) {
        if (c == k) {
            check(sum);
//            for (int i = 1; i <= k; ++i) { //输出子集
//                cout << b[i] << ' ';
//            }
//            cout << endl;
        }
        return;
    }
    dfs(p + 1, c, sum);

    b[c + 1] = a[p];
    dfs(p + 1, c + 1, sum + a[p]);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << count;
    return 0;
}
