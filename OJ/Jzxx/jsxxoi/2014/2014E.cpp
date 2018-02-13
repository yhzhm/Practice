/*2679: 【基础】简单单词接龙
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 107解决 : 42
题目描述
有n个单词（1≤n≤50），每个单词由2个小写字母组成，并约定第1个单词为龙头。
例如：n=7
7个单词为
aa
ac
ab
de
bh
hk
cd
接龙的方法为前一个单词的第2个字母和后一个单词的第1个字符相同，此时，可接的方法有：
aa—ac—cd 长度为3，即龙上有3个单词
aa—ab—bh—hk 长度为4
程序要求给出单词之后，求出最长龙的长度。
 
输入
第一行一个整数n
接下来n行，每行2个字母表示一个单词（单词字母间无空格）
 
输出
输出 一个整数，即最长的接长度（即龙上单词的个数）。
 
样例输入 [复制]
7
aa
ac
ab
de
bh
hk
cd
样例输出 [复制]
4
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2014江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Hz Yang on 2017/5/24.
//
#include <iostream>

using namespace std;
string s[55];
int n, b[55], count, maxi = 0;

void dfs(int x) {
    b[x] = 1;
    count++;
    maxi = max(count, maxi);
    for (int i = 2; i <= n; ++i) {
        if (!b[i] && s[x][1] == s[i][0]) dfs(i);
    }
    count--;
    b[x] = 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    dfs(1);
    cout << maxi << endl;
    return 0;
}
