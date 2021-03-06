/*2018: 【提高】加入数
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 723解决 : 221
题目描述
有一个长度不超过20位的整数（以字符串的形式给出），同时给出一个加入数字p，p可加入在整数的任何位置。加入之后，再删去一个数字，使剩下来的数最大。
例如：有整数： 1 2 3 4 5 6 7 8， P 为 5
得到的结果： 5 2 3 4 5 6 7 8
说明： 1 2 3 4 5 6 7 8 加入5之后成为： 5 1 2 3 4 5 6 7 8
再删去1最后得到： 5 2 3 4 5 6 7 8
 
输入
两行，第一行一个字符串，第二行一个正整数P
 
输出
经过处理操作后，得到的满足要求的数。
 
样例输入 [复制]
12345678
5
样例输出 [复制]
52345678
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2011年江苏省小学生信息学（计算机）奥赛*/

/*
237486，7
737486
4674085，2  考虑0的情况
46742085
8276943，6  考虑后面还有更大数的情况
8769643
24823，1    考虑p是最小数的情况
48231*/


//
// Created by Hz Yang on 2017/6/6.
// 插入：找比p小的数，插在该数之前（考虑特殊情况）；删：从头开始找，比之后一位小的数。
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size()) {
            s = s + p;
            break;//必须要有，不然i==s.size()永远成立
        } else if (s[i] < p[0]) {
            if (s[i] != '0' && i + 1 != s.size() && s[i + 1] >= p[0]) continue;
            s.insert(i, p);
            break;
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        if (i == s.size() - 1) s.erase(i, 1);
        else if (s[i] < s[i + 1]) {
            s.erase(i, 1);
            break;
        }
    }
    cout << s;
    return 0;
}
