/*1724: 【基础】整数拆段
时间限制 : 1 Sec内存限制 : 64 Mb提交 : 292解决 : 205
题目描述
将一个位数为L（4≤L≤10）的自然数N拆成4段，使各段对应的数的乘积最小。你能编一个程序实现吗？
 
输入
一个自然数N。
 
输出
一个整数，最小乘积。
 
样例输入 [复制]
321427
样例输出 [复制]
2268
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2007年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/18.
// pow函数的输出不确定，10^2输出99-_-!,所以自己写计算10的n次方的函数powt()
// 深搜求出所有的拆分组合，再拆分求解，注意数据类型long long
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
string s;
ll n,x, a[5],c[5],minx=0x7fffffff;
int powt(int n) //求10的n次方
{
    int sum=1;
    for (int i = 0; i < n; ++i) {
        sum*=10;
    }
    return sum;
}
void check()
{
//    for (int j = 1; j <=4 ; ++j) {//输出拆分情况
//        cout<<a[j]<<' ';
//    }
//    cout<<endl;
    ll sum=1,xx=x;
    for (int i = 4; i >=1 ; --i) {//根据拆分情况拆分数字，计算乘积
        int k;
        k = powt(a[i]);
        c[i]=xx%k;
        sum*=c[i];
        xx/=k;
//        cout<<k<<':'<<c[i]<<' ';
    }
//    cout<<sum<<endl;
    minx=min(sum,minx);
}

void dfs(int p,  int e) {
    if (p == 4) {
        a[p]=e;
        check();
        return;
    }
    for (int i = 1; i <= e; ++i) {
        a[p]=i;
        if (e - i>0) dfs(p + 1,  e - i);
    }
}

int main() {
    cin >> s;
    n=s.size();
    for (int i = 0; i < s.size(); ++i) {
        x=x*10+(s[i]-48);
    }
    dfs(1, n);

    cout<<minx;
    return 0;
}
