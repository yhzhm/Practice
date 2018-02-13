/*2020: 【提高】H数
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 763解决 : 226
题目描述
所谓H 数是指：仅包含质因子2，3，5，7的数。
例如：
2，3，4，5，6，7，8，9，10 均为H数
但 11 不是H数，12是H数，13不是H数，......
问题：给出一个N （10≤n≤3500），求出由小到大的第N 个H 数。
例如：当N=6 时，输出：7
 
输入
一个整数N
 
输出
一个整数（由小到大的第N 个H 数）
 
样例输入 [复制]
6
样例输出 [复制]
7
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2011年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/7.
// 用set去重，用优先队列排序，用vector可以不考虑数组大小
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

typedef long long LL;
priority_queue<LL, vector<LL>, greater<LL> > v;
set<LL> s;
const int dis[4] = {2, 3, 5, 7};
LL x, n, newx;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 10000) n--;
    v.push(1);
    s.insert(1);        //为了方便，第一个H数设置为1,所以后面要求第N+1个数
    for (int i = 1; i <= n + 1; i++) {
        x = v.top();
        v.pop();
        for (int j = 0; j < 4; j++) {
            newx = x * dis[j];
            if (!s.count(newx)) {
                s.insert(newx);
                v.push(newx);
            }
        }
    }
    cout << x << endl;
    return 0;
}