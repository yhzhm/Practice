/*题目描述
小明认为，如果以下条件之一成立，正整数 x 就是一个幸运数字:
1. x是4的倍数;
2. x是7的倍数;
3. x 转换为字符串后包含子串“44”或“77”。
例如，105 (7 的倍数), 442 (包含“44”), 1284 (4 的倍数)都是幸运数字，474 则不是。 编程统计 1 到 n 中幸运数字的数量。
 
输入
整数 n (1 ≤ n ≤ 1,000,000)
 
输出
一个整数:1, 2, ..., n中幸运数字的数量
 
样例输入
样例1: [复制]
32
样例2: [复制]
987654
样例输出
样例1: [复制]
11
样例2: [复制]
406754*/

//
// Created by Hz Yang on 2017/5/3.
//
#include <iostream>

using namespace std;

bool check(int i) {
    if (i % 4 == 0 || i % 7 == 0) return true;
    string s = to_string(i);
    if (s.find("44") != string::npos || s.find("77") != string::npos) return true;
    return false;
}

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (check(i)) sum++;
    }
    cout << sum;
    return 0;
}
