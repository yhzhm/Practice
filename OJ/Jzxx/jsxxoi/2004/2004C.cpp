/*1278: 【基础】n 的阶乘值问题
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 659解决 : 394
题目描述
阶乘是数学中的一种运算，n的阶乘表示为：n！=1*2*3*...*n。 编写程序，根据一个给出的n, 求得其阶乘值中所有数字之和P。并判断P是否为素数。
 
输入
键盘输入一个自然数n （1≤ n ≤ 100 ）。
 
输出
n的阶乘值的所有数字之和P，若P为素数输出“T”，否则输出“F”。
 
样例输入
样例1: [复制]
5
样例2: [复制]
20
样例输出
样例1: [复制]
3□T
样例2: [复制]
54□F
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
江苏省青少年信息学奥林匹克竞赛（JSOI2004）小学组复赛*/

//
// Created by Hz Yang on 2017/6/14.
// 高精度阶乘
#include <cstdio>
#include <iostream>

using namespace std;
bool isp(int n)
{
    if(n<2) return false;
    for (int i = 2; i*i <= n ; ++i) {
        if(n%i==0) return false;
    }
    return true;
}
int main() {
    int n,a[200]={0},lena,sum=0;
    a[1]=1;lena=1;
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=lena ; ++j) {
            a[j]*=i;
        }
        for (int j = 1; j <=lena ; ++j) {
            a[j+1]+=a[j]/10;
            a[j]%=10;
        }
        while(a[lena+1]>0){
            lena++;
            a[lena+1]+=a[lena]/10;
            a[lena]%=10;
        }
    }
    for (int i = 1; i <=lena ; ++i) {
        sum+=a[i];
    }
    cout<<sum<<' ';
    if(isp(sum)) cout<<'T';
    else cout<<'F';

    return 0;
}
