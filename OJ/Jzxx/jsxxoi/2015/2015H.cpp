/*2878: 【基础】加数
时间限制 : 1 Sec内存限制 : 128 Mb提交 : 211解决 : 189
题目描述
给出一个正整数n（1≤n≤100000）。在n的右边加入n的一半，然后在新数的右边再加入n的一半的一半，一直进行，直到不能再加为止。
例如  n=37         37的一半为18（取整数）加到n的右边成为
        3718         18的一半为9，加到新数的右边成为
        37189        9的一半为4，加到新数的右边成为
        371894       4的一半为2，加到新数的右边成为
        3718942      2的一半为1，加到新数的右边成为
        37189421     1的一半为0，加数结束，最后得到的数是一个8位的数
 
输入
整数n 
 
输出
加数结束后新数的长度。
 
样例输入 [复制]
37
样例输出 [复制]
8
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2015江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Hz Yang on 2017/5/16.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin>>n;
    string s="";
    while (n > 0) {
        s+=to_string(n);
        n/=2;
    }
    cout<<s.size()<<endl;
    return 0;
}