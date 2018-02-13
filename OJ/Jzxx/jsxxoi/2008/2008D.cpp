/*
4、重排数
【问题描述】
读入二个数据文件，然后程序要完成如下的操作：
第一步  将2个文件的数合并在一起，
第二步  将合并好的数由大到小排序，
第三步  重新排列，从第一个数起开始编号，然后将奇数号上的数（样例中的13，9，5）从前向后排，偶数号上的数（样例中的12，7，4）从后往前排。
第四步  计算，将排好的数，第一个+第二个数的2倍+第三个数的3倍+…
第五步  输出计算的结果。
【输　 入】：
输入2个文件名（文件名后缀.IN），读入二个文本文件，文件的格式为：
     第一行是一个整数 n(1≤n≤10)，
第二行有n个整数，整数范围在1~100之间，数与数之间有一个“，”号。
【输　 出】：输出到屏幕 。一个整数（最后计算的结果）。
【样 　例】：
输入：w1,w2
文件读入：
4
12, 4, 5, 9
2
13, 7
输出:
169
【样例说明】：
第一步合并后为：12  4  5   9  13  7
第二步上例中的数成为：13  12  9  7  5  4
第三步得到：13  9  5  4  7  12
第四步计算后为：13+2×9+3×5+4×4+5×7+6×12=169
最后输出  169
*/


//
// Created by Hz Yang on 2017/6/19.
// 又一题oj上题目描述不严谨的，没有样例说明，就不能确定题目中的往前排和往后排是什么意思

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mfbig(int i, int j) {
    return i > j;
}

int main() {
    int n, x;
    vector<int> v, v1, v2;
    for (int i = 0; i < 2; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> x;
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end(), mfbig);//用自定义函数从大到小排列
    for (int i = 0; i < v.size(); ++i) {
        if (i % 2 == 0) v1.push_back(v[i]);//奇数位（因为从0开始，所以判断条件是偶数）push到v1
        else v2.push_back(v[i]);//偶数位push到v2
    }
    sort(v2.begin(), v2.end());//v2从小到大排列
    int j = 0, sum = 0;//j用来表示是第几个数，sum保存累加和
    for (int i = 0; i < v1.size(); ++i) {
        sum += v1[i] * (++j);
    }
    for (int i = 0; i < v2.size(); ++i) {
        sum += v2[i] * (++j);
    }
    cout << sum;
    return 0;
}



