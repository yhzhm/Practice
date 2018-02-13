/*34:回文子串
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符串，输出所有长度至少为2的回文子串。

回文子串即从左往右输出和从右往左输出结果是一样的字符串，比如：abba，cccdeedccc都是回文字符串。

输入
一个字符串，由字母或数字组成。长度500以内。
输出
输出所有的回文子串，每个子串一行。
子串长度小的优先输出，若长度相等，则出现位置靠左的优先输出。
样例输入
123321125775165561
样例输出
33
11
77
55
2332
2112
5775
6556
123321
165561*/
//
// Created by Hz Yang on 2017/4/6.
//
#include <iostream>

using namespace std;

bool palindrome(string s) {
    string::size_type i;
    for (i = 0; i < s.size() >> 1; ++i) {
        if (s[i] != s[s.size() - i - 1]) return 0;
    }
    return 1;
}

int main() {
    string s, t;
    getline(cin, s);
    string::size_type i, j;
    for (i = 2; i <= s.size(); ++i) {
        for (j = 0; j <= s.size() - i; ++j) {
            if (t != s.substr(j, i)) t = s.substr(j, i);
            if (t.size() < 2) continue;
            if (palindrome(t)) cout << t << endl;
        }
    }
    return 0;
}
