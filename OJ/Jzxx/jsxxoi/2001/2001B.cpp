/*1261: 【基础】字符串操作
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 1040解决 : 635
题目描述
输入三个字符串A，B，C，要求在A中查找B，找不到则输出0，找到则将A中的B用C去替换，然后输出替换后的A。
 
输入
三行，一行一个字符串。 A B C
 
输出
若在A中不存在B，则输出 0 若A存在B，则输出替换后的A。
 
样例输入 [复制]
示例1：
ABCDEFGHIJ
XY
WWW

示例2：
ABCDEFGHIJ
CDE
WWWK

示例3：
ABXYZCDXYZ
XYZ
XY
样例输出 [复制]
示例1：
0

示例2：
ABWWWKFGHIJ

示例3：
ABXYCDXYZ
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

int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    int i=a.find(b);
    if(i==-1) cout<<'0';
    else {
        a.erase(i,b.size());
        a.insert(i,c);
    }
    cout << a;
    return 0;
}

