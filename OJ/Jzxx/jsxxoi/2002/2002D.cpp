/*1275: 【基础】圆环上求素数III
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 230解决 : 98
题目描述
将 1，2，…… n 个数（n <= 7）按顺时针方向排成一圈，然后从任意位置开始按顺时针方向连续取 k个数字组成一个k位数。（k< n） 例如：n=3 k=2 按顺时针方向排成如下一圈：
 
此时，可组成：12，23，31。 其中素数有：23 ，31两个。 问题一：当给出n、k后，求出在n个k位数中有多少个素数？ 问题二：将这n个数重新排列，找出能产生k位数中的素数最多的一种排列，并统计出可能产生的素数个数。 输入：n k 输出：X1 ‘问题一的解 X2 ‘问题二的解（仅需个数，不用输出排列）
 
输入
n k
 
输出
X1 X2
 
样例输入 [复制]
3 2
样例输出 [复制]
2
2
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2002江苏省青少年信息学奥林匹克小学组竞赛复赛*/
//
// Created by Hz Yang on 2017/6/12.
//
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

bool isp(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, k, a[10], cnt, first = 1, maxn = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    do {
        int s = 0;
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                s = s * 10 + a[(i + j) % n];
            }
            if (isp(s)) cnt++;
            s = 0;
        }
        if (first) {
            cout << cnt << endl;
            first = 0;
        } else maxn = max(cnt, maxn);
    } while (next_permutation(a, a + n));
    cout << maxn;
    return 0;
}

