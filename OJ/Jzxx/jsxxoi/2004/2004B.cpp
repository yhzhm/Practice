/*1277: 【基础】找最长单词
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 1081解决 : 421
题目描述
编写程序，根据给出的一个结束于'.'的字符字串，找出其中最长的含有字母'a'的子串。
 
输入
一行，为一个字符字串，结束于句点'.'。字串中的子串由一个或几个空格隔开。
 
输出
一行。显示找出的最长的含有字母'a'的子串。如果有多个这样的了串，只显示其中的第一个；若没有含字母'a'的子串，则显示'NO'。
 
样例输入 [复制]
Her□□name□is□Lilan□□□and□she□□is□a□□ happy□□student.
（□：表示一个空格）
样例输出 [复制]
Lilan
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
江苏省青少年信息学奥林匹克竞赛（JSOI2004）小学组复赛*/

//
// Created by Hz Yang on 2017/6/14.
//
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string s, s1 = "", s2 = "";
    getline(cin, s);
    string::size_type i, maxd = 0;
    for (i = 0; i < s.size(); ++i) {
        if (s[i] == ' ' || s[i] == '.') {
            if (s1.find('a') != -1 && s1.size() > maxd) {
                maxd = s1.size();
                s2 = s1;
            }
            s1 = "";
        } else s1 = s1 + s[i];
    }
    if (s2 == "") cout << "NO";
    else cout << s2;
    return 0;
}
