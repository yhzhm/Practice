/*1763: 【基础】夏令营旗手
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 434解决 : 329
题目描述
2009江苏省“信息与未来”夏令营活动在南师大附小举行，小明同学被选为小旗手。 小明家住在解放路，解放路的人喜欢数字，所以门牌号码的编制很特别，它们是：2, 3, 5, 7, 11, … 即门牌号码全部为从2开始的素数。可惜小明家的号码被盖起来无法看到了，但小明的同学提供了一个有用信息：除去小明家的门牌号之后，其他人家的门牌号的和为k。
问题：当k给出后（保证有解），请计算出：
①小明家的门牌号是多少？
② 解放路共有多少户人家？
 
输入
一个整数k（2＜k≤ 5000）
 
输出
二个整数（小明家的门牌号码及解放路人家户数）。
 
样例输入 [复制]
15
样例输出 [复制]
2 4
提示[+]
样例说明】：解放路共有4户人家，其门牌号码为２,３,５,７, 小明家的门牌号码为2。
来源
2009年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/19.
//
#include <cstdio>
#include <iostream>

using namespace std;

bool isp(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int k, i = 0, s = 0, cnt = 0;
    cin >> k;
    while (s <= k) {
        if (isp(++i)) {
            s += i;
            cnt++;
        }
    }
    cout << s - k << ' ' << cnt;
    return 0;
}