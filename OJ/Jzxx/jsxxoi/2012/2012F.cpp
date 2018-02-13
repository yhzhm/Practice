/*2245: 【基础】哨兵
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 419解决 : 140
题目描述
在一个n×m的方格中，每个格点上站有一个人，如下图n=3，m=4的方格中；

共站有12人。在方格的左上角A点有一个哨兵，他能看到的人有A，B，E，F，G，H，J，L格点上的人数共8人，C，D格点被B挡住，I格点被E挡住，K格点被F挡住，所以C，D，I，K格点上的人看不到。
那么，当n，m给出之后(2≤n，m≤100)，哨兵可以看到多少人。
 
输入
二个整数n，m。
 
输出
一个整数，即哨兵可以看到的人数。
 
样例输入 [复制]
4 4
样例输出 [复制]
10
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2012江苏省青少年信息学奥林匹克小学组竞赛复赛*/
//
// Created by Hz Yang on 2017/6/5.
// 用三角函数tan，判断是否在一条线上
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int n, m;
    set<double> set1;
    double x, y;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            x = i;
            y = j;
            set1.insert(tan(y / x));
        }
    }
    cout << set1.size() + 3;
    return 0;
}

