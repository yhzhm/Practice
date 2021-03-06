/*1902: 【基础】评最优志愿者
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 846解决 : 267
题目描述
建湖实小精心安排了本次夏令营活动，挑选了N 名小志愿者为活动提供服务，依次编号为1，2，...N，同时聘请了K 名参加活动的带队老师对小志愿者进行评选打分。小志愿者中得到评分之和最高者，即为最优志愿者（若有多人同分，同分者则全部入选）。
 
输入
第一行有二个整数（2 ≤N，K ≤100），接下来的K行每行有N 个整数（表示每位评委依次对各个小志愿者的打分，所打的分数均为1...100之间一个整数）。
 
输出
若干行，每行一个最优志愿者的编号（从小到大）。
 
样例输入 [复制]
3 2
50 60 70
37 48 28
样例输出 [复制]
2
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2011年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/6.
//
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main()
{
    int n,k,a[105]={0},x,maxd=0;
    cin >> n >> k;
    for (int i = 1; i <=k ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            cin >> x;
            a[j]+=x;
            maxd=max(a[j],maxd);
        }
    }
    for (int i = 1; i <= n ; ++i) {
        if(a[i]==maxd) cout<<i<<endl;
    }
    return 0;
}
