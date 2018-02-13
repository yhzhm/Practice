/*1808: 【基础】计算表达式
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 520解决 : 419
题目描述
表达式的形式如：3+5*6-4 其中, 运算数为一位整数,运算符为 +、-、* 三种，且运算符没有优先级的区分，一律自左向右计算。 如上例的计算过程为：3+5*6-4=8*6-4=48-4=44
 
输入
一行，即表达式字符串（长度小于100）
 
输出
一个整数，即表达式的计算结果（结果在-20000至20000之间）
 
样例输入 [复制]
3+5*6-4
样例输出 [复制]
44
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2010年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/9.
//
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int sum=s[0]-48;
    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]){
            case '+':sum+=s[i+1]-48; break;
            case '-':sum-=s[i+1]-48; break;
            case '*':sum*=s[i+1]-48; break;
        }
    }
    cout<< sum;
    return 0;
}

