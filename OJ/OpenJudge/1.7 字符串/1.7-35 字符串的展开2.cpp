/*总时间限制: 1000ms 内存限制: 65536kB
描述
在初赛普及组的“阅读程序写结果”的问题中，我们曾给出一个字符串展开的例子：如果在输入的字符串中，含有类似于“d-h”或者“4-8”的字串，我们就把它当作一种简写，输出时，用连续递增的字母获数字串替代其中的减号，即，将上面两个子串分别输出为“defgh”和“45678”。在本题中，我们通过增加一些参数的设置，使字符串的展开更为灵活。具体约定如下：

(1) 遇到下面的情况需要做字符串的展开：在输入的字符串中，出现了减号“-”，减号两侧同为小写字母或同为数字，且按照ASCII码的顺序，减号右边的字符严格大于左边的字符。

(2) 参数p1：展开方式。p1=1时，对于字母子串，填充小写字母；p1=2时，对于字母子串，填充大写字母。这两种情况下数字子串的填充方式相同。p1=3时，不论是字母子串还是数字字串，都用与要填充的字母个数相同的星号“*”来填充。

(3) 参数p2：填充字符的重复个数。p2=k表示同一个字符要连续填充k个。例如，当p2=3时，子串“d-h”应扩展为“deeefffgggh”。减号两边的字符不变。

(4) 参数p3：是否改为逆序：p3=1表示维持原来顺序，p3=2表示采用逆序输出，注意这时候仍然不包括减号两端的字符。例如当p1=1、p2=2、p3=2时，子串“d-h”应扩展为“dggffeeh”。

(5) 如果减号右边的字符恰好是左边字符的后继，只删除中间的减号，例如：“d-e”应输出为“de”，“3-4”应输出为“34”。如果减号右边的字符按照ASCII码的顺序小于或等于左边字符，输出时，要保留中间的减号，例如：“d-d”应输出为“d-d”，“3-1”应输出为“3-1”。

输入
包括两行：
第1行为用空格隔开的3个正整数，一次表示参数p1，p2，p3。
第2行为一行字符串，仅由数字、小写字母和减号“-”组成。行首和行末均无空格。

40%的数据满足：字符串长度不超过5；
100%的数据满足：1<=p1<=3，1<=p2<=8，1<=p3<=2。字符串长度不超过100。
输出
只有一行，为展开后的字符串。
样例输入
样例 #1：
1 2 1
abcs-w1234-9s-4zz

样例 #2：
2 3 2
a-d-d

样例 #3：
3 4 2
di-jkstra2-6
样例输出
样例 #1：
abcsttuuvvw1234556677889s-4zz

样例 #2：
aCCCBBBd-d

样例 #3：
dijkstra2************6
来源
NOIP2007复赛 提高组 第二题*/

//
// Created by Hz Yang on 2017/4/21.
//
#include <iostream>
using namespace std;
int p1, p2, p3;
string s;

string gensubstr(char pre, char next) {
    string s2, s1;
    char cbegin, cend;
    if (p1 == 1) {
        cbegin = tolower(pre) + 1;
        cend = tolower(next) - 1;
    }
    if (p1 == 2) {
        cbegin = toupper(pre) + 1;
        cend = toupper(next) - 1;
    }
    if (p1 == 3) {
        cbegin = pre + 1;
        cend = next - 1;
    }
    for (int i = cbegin; i <= cend; ++i) {
        for (int j = 1; j <= p2; ++j) {
            if (p1 == 3) s1 += '*';
            else s1 += char(i);
        }
    }
    if (p3 == 1) return s1;
    if (p3 == 2) {
        string s2(s1.rbegin(), s1.rend());
        return s2;
    }
}

int main() {

    cin >> p1 >> p2 >> p3;
    cin >> s;
    string::size_type i;
    cout << s[0];
    for (i = 1; i != s.size() - 1; ++i) {
        char cb = s[i - 1], ce = s[i + 1];
        if (s[i] == '-' &&  cb < ce) {
            if (islower(cb) && islower(ce)
                    || isupper(cb) && isupper(ce)
                    || isdigit(cb) && isdigit(ce) ) {
                if (cb == ce - 1) continue;
                else cout << gensubstr(cb, ce);
            } else cout << s[i];
        } else cout << s[i];
    }
    cout << s[s.size() - 1] << endl;
    return 0;
}