/*1725: 【基础】压缩数据的解压
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 466解决 : 375
题目描述
读取一些被压缩的数据，进行解压，再根据题目要求将结果输出。
 
输入
它的第一行为一个正整数k，指明以下的数据分为k段。
第二行是k段压缩数据串，每个段有两种格式（数之间用一个空格分隔）： 如果每段第1个数n为正，则该段只有两个数，其解压操作是将该段的第2个数重复n次； 如果每段第1个数n为负数，则该段有|n|+1个数，其解压操作是重复该段从第2个数开始的|n|个数一次。（注：|n|表示取n的绝对值）
 
输出
经解压后得到的整数串上所有数字之和。
 
样例输入 [复制]
5
3 2 -5 0 1 2 3 4 5 1 5 0 -4 4 3 2 1
样例输出 [复制]
31
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2007年江苏省小学生信息学（计算机）奥赛*/
//
// Created by Hz Yang on 2017/6/18.
// 分析题目后发现，可以不用数组保存输入的数据，直接根据读入的数字进行判断，然后作相应处理
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    int k,sum=0,x,y;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        if(x>0) {
            cin>>y;
            for (int j = 0; j < x; ++j) {
                sum+=y;
            }
        }else{
            x=-x;
            for (int j = 0; j < x; ++j) {
                cin>>y;
                sum+=y;
            }
        }
    }
    cout<<sum;
    return 0;
}
