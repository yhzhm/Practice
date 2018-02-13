/*2882: 【基础】字符串替换
时间限制 : 1 Sec内存限制 : 128 Mb提交 : 96解决 : 58
题目描述
小明最近迷上了字符串操作。对每个字符串，小明每次可以执行以下两种操作之一:
1. 把字符串中的某个字符改成任意一个其他字符，花费1的代价。
2. 交换字符串中的两个字符，花费0的代价。
小明发现，把一个字符串通过一系列的操作，可以转换成任何一个与之等长的字符串。例如，把 “hello”变为“world”的一种代价为 3 的操作序列如下:
1. hello → wello (替换 h 为 w，代价为 1)
2. wello → wolle (交换 e 和 o，代价为 0)
3. wolle → worle (替换 l 为 r，代价为 1)
4. worle → world (替换 e 为 d，代价为 1)
小明发现，无法用少于 3 次的代价将“hello”变为“world”。 显然，不同的转换方案花费的代价是不同的，请编程帮助小明计算把一个字符串变为另一个字符 串的最小代价。
本题中的字符串根据给定的初始数值 s 按以下规则生成:
for i = 1, 2, ... n
  s ← (s × 345) mod 19997
  第一个字符串的第 i 个字符的 ASCII 码为(97 + (s mod 26))
for i = 1, 2, ... n
  s ← (s × 345) mod 19997
  第二个字符串的第 i 个字符的 ASCII 码为(97 + (s mod 26))
 
输入
正整数 n (字符串长度), s (数据生成器的初始数值)。1 ≤ n ≤ 1,000，1 ≤ s ≤ 19,997。
 
输出
将第一个字符串转换为第二个字符串的最少代价。
 
样例输入
样例1: [复制]
4 35
样例2: [复制]
100 31
样例输出
样例1: [复制]
2
样例2: [复制]
29*/
//
// Created by Hz Yang on 2017/5/3.
//
#include <iostream>

using namespace std;

int main() {
    int n, s, sum = 0, a[256] = {0}, b[256] = {0};
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        s = s * 345 % 19997;
        a[97 + (s % 26)]++;
    }
    for (int i = 0; i < n; ++i) {
        s = s * 345 % 19997;
        b[97 + (s % 26)]++;
    }
    for (int i = 0; i < 256; i++) {
        sum += min(a[i], b[i]);
    }
    cout << n - sum << endl;
    return 0;
}