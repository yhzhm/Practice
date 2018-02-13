/*1718: 【基础】选夏令营旗手
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 731解决 : 384
题目描述
每年的“信息与未来”小学生夏令营活动，组织者均设计安排了许多有趣的活动。去年小明与许多同学一起参加的走迷宫就是其中的一项，他经过努力并取得了好成绩。 今年小明又怀着极大的兴趣来到了营地，首先看到组织者贴出的一个海报：挑选本次夏令营的旗手！由于报名的营员非常多，于是只好规定让所有参加的N个人坐成一圈，并按顺时针方向从1～N编号。由第1人开始进行1～M报数，报到M的人出圈，再从下一个人重新开始从1到m报数。如此进行下去，直到剩下一人为止，就是本次夏令营的旗手。 小明非常渇望能成为旗手，你能编一个程序帮助他实现愿望吗？如果可以的话，你的程序应输出小明在圈中的编号。
 
输入
输入二个整数N，M （2≤N，M≤100，N≥ M ），之间用一个空格分隔。
 
输出
一个整数，表示小明在圈中的编号。
 
样例输入 [复制]
9 3
样例输出 [复制]
1
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2006年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/17.
//
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    while (q.size() > 1) {
        for (int i = 1; i < m; ++i) {
            int x = q.front();
            q.push(x);
            q.pop();
        }
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}