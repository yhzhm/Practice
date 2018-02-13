/*
2038: 【基础】贝贝的图形
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 696解决 : 337
题目描述
贝贝最近玩起了字符游戏，规则是这样的：读入一行字符串，其中的字母都是大写的，乐乐想打印一个柱状图显示每个大写字母的频率。你能帮助他吗？
请严格地按照输出样例来安排你的输出格式。
 
输入
一行字符，由大写字母、空格或标点组成，每行不超过255个字符。
 
输出
由若干行组成，第一行由空格和26个大写字母组成，字母之间空一格；后面几行由空格和星号组成。在任何一行末尾不要打印不需要的多余空格，也不要打印任何多余的空行。
 
样例输入 [复制]
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
样例输出 [复制]
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
* * * * * * * * * * * * * * * * * *   * * * * * * *
      * *     *             *     *   * *
        *                   *
        *                   *
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
武进区第5届程序设计比赛题（初中）*/

//
// Created by Hz Yang on 2017/6/7.
// 这题是常州市赛题，省赛题应该是求完全数的个数
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int a[128+10]={0},first=1,maxd=0;
    string s;
    getline(cin ,s);
    for (int i = 0; i < s.size(); ++i) {
        if(isupper(s[i])) {
            a[s[i]]++;
            maxd=max(a[s[i]],maxd);
        }
    }
    for (int j = 65; j <= 90; ++j) {
        if(first) first=0; else printf(" ");
        printf("%c",j);
    }
    printf("\n");
    for (int i = 1; i <=maxd ; ++i) {
        first=1;
        for (int j = 65; j <= 90; ++j) {
            if(first) first=0; else printf(" ");
            if(a[j]) {printf("*");a[j]--;}
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}


