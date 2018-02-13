/*1260: 【基础】数的排序
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 1724解决 : 897
题目描述
输入n个不超过30000的整数（n≤10）。然后求出每个数的数字和，再按每个数的数字和由小到大排列输出。
 
输入
第一行为整数n 第二行为n个整数
 
输出
由小到大排列的每个数的数字和（每个数之间保留一个空格）
 
样例输入 [复制]
4
33 104 87 16
样例输出 [复制]
5 6 7 15
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2001江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Hz Yang on 2017/6/9.
//
#include <cstdio>
#include <iostream>
using namespace std;

int check(int n)
{
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int n,x,a[50]={0};
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x;
        a[check(x)]++;
    }
    for (int j = 0; j < 50 ; ++j) {
        while(a[j]){
            cout<<j<<' ';
            a[j]--;
        }
    }
    return 0;
}

