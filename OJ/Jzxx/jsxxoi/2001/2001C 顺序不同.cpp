/*1268: 【基础】算24
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 661解决 : 269
题目描述
给出4个1到1000之间的整数，用这4个整数，通过+、–、*的运算而得到24，运算规则如下： 1．每个数必须使用一次，只能使用一次 2．运算符无优先级之分，自左向右计算。
例如：输入4个数为2 9 3 1
      则计算方法为2+1*9-3=24

例如：输入：1 1 2 2              输入：4 4 4 4
      输出：error                输出：4*4+4+4=24
 
输入
4个1到1000之间的整数
 
输出
若4个数不能产生出24，则输出error； 若能产生，则输出产生式（若有多个，仅能输出一个）。
 
样例输入 [复制]
示例1:
5 7 4 9　　　    　　　　　　　　　　　　　　　　　

示例2:
9 13 7 2

示例3:
5 1 3 5　　　　　　　　　

示例4:
8 9 5 2
样例输出 [复制]
示例1:
7-4*5+9=24

示例2:
9-7*13-2=24

示例3:
error

示例4:
8+9+5+2=24
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2001江苏省青少年信息学奥林匹克小学组竞赛复赛*/

//
// Created by Hz Yang on 2017/6/12.
// 多个答案，输出哪个？
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int a[4];
int work(int a,char x,int b)
{
    switch (x){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
    }
}
bool check(char op1,char op2,char op3)
{
    int x=work(a[0],op1,a[1]);
    int y=work(x,op2,a[2]);
    int z=work(y,op3,a[3]);
    if(z==24) {
        printf("%d%c%d%c%d%c%d=24\n",a[0],op1,a[1],op2,a[2],op3,a[3]);
        return true;
    }
    return false;
}
int main()
{
    char op[]={'+','-','*'};
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }
//    sort(a,a+4);
    do{
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                   if( check(op[i],op[j],op[k])) {return 0;}
                }
            }
        }
    }while(next_permutation(a,a+4));
    cout<<"error";
    return 0;
}

