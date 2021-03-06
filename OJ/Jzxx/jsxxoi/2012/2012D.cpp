/*2243: 【基础】奇怪的数
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 469解决 : 224
题目描述
对于末尾为6的一个整数n，将末尾的6移到此数的最高位前面，可以得到一个新数，若新数为原数的4倍，则称原数为奇怪的数。
 
输入
无
 
输出
一行包含两个整数，即最小的奇怪的数和次小的奇怪的数，用一个空格隔开。
 
样例输入 [复制]
样例输出 [复制]
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2012江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Yhz on 2017/5/31.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long  x;
    int count = 0;
    for (int i = 1; count < 2; i++) {
        x = 6 * pow(10, i) - 24;
        if (x % 39 == 0) {
            cout << x / 39 * 10 + 6 << ' ';
            count++;
        }
    }
    return 0;
}
