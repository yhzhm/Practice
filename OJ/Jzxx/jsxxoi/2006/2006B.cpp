/*1719: 【基础】找最长良序字符串
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 1269解决 : 661
题目描述
我们将“ABC”或“ACEG”等类似的字串称为良序字串（因为它们是按ASCII码排列的），而像“ACB”或“ACCD”或“AGCD”则不可称为良序字串。 编写程序，将键入的一串字符中的最长良序字串找出来，输出其长度。
 
输入
读入一串字符（长度≤30）。
 
输出
一个最长良序字串的长度。
 
样例输入 [复制]
2345135791246823456
样例输出 [复制]
5
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2006年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/16.
//
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int maxd=0,p=0,cnt=1;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]<s[i+1]) cnt++;
        else{
            maxd=max(cnt,maxd);
            p=i;
            cnt=1;
        }
    }
    cout<<maxd;
    return 0;
}
