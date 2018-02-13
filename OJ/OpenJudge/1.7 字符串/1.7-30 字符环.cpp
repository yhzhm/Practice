/*30:字符环
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有两个由字符构成的环。请写一个程序，计算这两个字符环上最长连续公共字符串的长度。例如，字符串“ABCEFAGADEGKABUVKLM”的首尾连在一起，构成一个环；字符串“MADJKLUVKL”的首尾连在一起，构成一个另一个环；“UVKLMA”是这两个环的一个连续公共字符串。

输入
一行，包含两个字符串，分别对应一个字符环。这两个字符串之间用单个空格分开。字符串长度不超过255，且不包含空格等空白符。
输出
输出一个整数，表示这两个字符环上最长公共字符串的长度。
样例输入
ABCEFAGADEGKABUVKLM MADJKLUVKL
样例输出
6*/

#include <iostream>

using namespace std;

void check(string sx, string sy) {
    string sa = sx + sx, sb = sy + sy;
    string::size_type i, j;
    for (i = sy.size(); i >= 1; --i) {
        for (j = 0; j < sy.size(); ++j) {
            if (sa.find(sb.substr(j, i)) != -1) {
                cout << i << endl;
                return;
            }
        }
    }


}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() >= s2.size()) check(s1, s2);
    else check(s2, s1);
    return 0;
}