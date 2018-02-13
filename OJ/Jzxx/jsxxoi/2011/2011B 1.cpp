/*1903: 【基础】夏令营旗手
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 403解决 : 288
题目描述
2011年江苏省“信息与末来”夏令营在建湖实小进行，营委会按照惯例将在该校学生中挑选一位小旗手，今年的挑选方法如下：
由学校推荐N 名学生（100 ≤N ≤10000），将他们依次编号为1，2，...N，然后：
1）求出2 到 N 之间的全部素数，将它们记为X1，X2，... Xk
2）将得到的这K 个素数，每个素数加上它的序号。如：2是最小素数，则2+1，3是第二个素数，则3+2，...如此操作后得到新的K 个数Y1，Y2，... Y k
3）再找出Y1，Y2，... Y k 中的素数Z1，Z2，... Z m
4）将这m 个素数相加，得到的和除以（N+1）后得到的余数，该余数所表示的编号学生即为挑选到的小旗手。
 
输入
一个整数N
 
输出
一个整数（挑选到的小旗手的编号）
 
样例输入 [复制]
121
样例输出 [复制]
92
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
bool isPrime(int n)
{
    if(n<2) return false;
    for (int i = 2; i*i <= n; ++i) {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n,j=0,a[10000],x,sum=0;
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        if(isPrime(i)) a[++j]=i;
    }
    for (int i = 1; i <=j ; ++i) {
        x = a[i] + i;
        if (isPrime(x)) sum += x;
    }
    cout<<sum%(n+1)<<endl;
    return 0;
}
