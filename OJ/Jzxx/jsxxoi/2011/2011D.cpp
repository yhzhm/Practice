/*2017: 【提高】优美连接
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 450解决 : 277
题目描述
给出n个2位整数（1≤n≤10），将这n个数拼成一个长2n位长整数：y=x1 x2 x3……x2n
然后进行计算: d=│x1-x2│+│x2-x3│+….+ │x2n-1-x2n│
问题：当n个数给出之后，找出一种拼接方法，使d最小。
例如：n=3 时，三个数分别为： 26,17,34
拼接方法有：
26 17 34 d=│2-6│+│6-1│+│1-7│+│7-3│+│3-4│=20
26 34 17 d=│2-6│+│6-3│+│3-4│+│4-1│+│1-7│=17
……
17 34 26 d=│1-7│+│7-3│+│3-4│+│4-2│+│2-6│=17
其中最小d为17
 
输入
第一行一个整数n，第二行n个整数
 
输出
一个整数，即最小的d
 
样例输入 [复制]
3
26 17 34
样例输出 [复制]
17
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2011年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/6.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a[11], sum = 0, mind = 1000;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    do {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += abs(a[i] / 10 - a[i] % 10);
            if (i + 1 != n) sum += abs(a[i] % 10 - a[i + 1] / 10);
        }
        mind = min(sum, mind);
    } while (next_permutation(a, a + n));
    cout << mind;
    return 0;
}
