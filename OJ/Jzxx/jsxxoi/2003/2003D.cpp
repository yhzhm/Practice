/*1274: 【基础】回文数列
时间限制 : 4 Sec内存限制 : 16 Mb提交 : 293解决 : 210
题目描述
对一个正整数K，求出K的所有拆分，并统计输出其中回文数列的个数。 所谓回文数列是指该数列中的所有数字，从左向右或从右向左看都相同。 例如： K=4时，有如下的拆分： 4=1+1+1+1	{回文数列1} =1+1+2 =1+2+1	{回文数列2} =2+1+1 =2+2	{回文数列3} =1+3 =3+1 回文数列共有3个
 
输入
一个正整数K（ 1< K ≤ 26 ）。
 
输出
满足条件的回文数列的个数。
 
样例输入 [复制]
4
样例输出 [复制]
3
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2003年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/15.
// 直接判断记录拆分情况的数组
#include <cstdio>
#include <iostream>
using namespace std;
int n,cnt,a[30];

bool check(int *a,int p)
{
    int mid=p/2;
    for (int i = 1; i <=mid ; ++i,--p) {
        if(a[i]!=a[p]) return false;
    }
    return true;
}


void dfs(int p,int n)
{
    if(n==0) {cnt+=check(a,p-1);return;}
    for (int i = 1; i <=n ; ++i) {
        a[p]=i;
        dfs(p+1,n-i);
        a[p]=0;
    }
}
int main() {
    cin >> n;
    dfs(1,n);
    cout<< cnt-1;
    return 0;
}


