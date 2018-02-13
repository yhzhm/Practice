/*2871: 【基础】夏令营小旗手
时间限制 : 1 Sec内存限制 : 128 Mb提交 : 251解决 : 144
题目描述
2015年江苏省《信息与未来》小学夏令营在洪泽县实验小学进行，组委会决定在洪泽县实验小学的学生中推选一名小旗手，推选方法如下：
洪泽县实验小学有n名学生（1≤n≤1000）。每名学生有一个学号，学号为1,2,…n。同时，每名同学有一张选票，可以推选一名同学为小棋手。最后，得票最多者当选，若得票最多者相同票数，则学号小者当选。
例如，选票为2 3 4 4 3 4 1 6，4号学生得票最多（3票）当选小棋手。
输入
n，x1两个整数，n为学生数，x1为第一个选票上的学号，之后的选票 xi(i≥2)由下面的递推关系给出：
xi=(xi-1×37+33031)  mod n+1
其中mod为取余运算，例如，13 mod 8=5，21 mod 21=0。根据这个公式，就能从x1推出x2,x3,...,xn。
输出
一个整数，即选出的小棋手的学号。
样例输入 [复制]
5 2
样例输出 [复制]
2*/

//
// Created by Hz Yang on 2017/5/8.
//
#include <iostream>
using namespace std;

int main() {
    int n, x, a[1010] = {0}, max = 0,pos;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        a[x]++;
        x = (x * 37 + 33031) % n + 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] > max) {max = a[i];pos=i;}
    }
    cout << pos << endl;
    return 0;
}
