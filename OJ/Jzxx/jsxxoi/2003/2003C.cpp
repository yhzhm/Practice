/*1273: 【基础】均匀划分
时间限制 : 1 Sec内存限制 : 16 Mb提交 : 396解决 : 232
题目描述
有两个正整数K与P，然后将K分成P个部分：K1，K2，……Kp，要求找出一种分法，满足：K1＋K2＋……＋Kp＝K，并使K1×K2×……×Kp为最大。 例如：K=4，P=2，则分法有： 4＋0＝4 3＋1＝4 2＋2＝4 其中乘积最大者为：2×2＝4
 
输入
输入两个正整数K与P（2 ≤ K ≤ 35，P < K ），输入不必查错。
 
输出
满足条件的最大乘积的一种分法。
 
样例输入
样例1: [复制]
4 2（也就是K=4，P=2）
样例2: [复制]
17 3
样例输出
样例1: [复制]
2*2＝4
样例2: [复制]
5*6*6=180
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2003年江苏省小学生信息学（计算机）奥赛试题*/

//
// Created by Hz Yang on 2017/6/12.
// 可参考2010D输出解
#include <cstdio>
#include <iostream>

using namespace std;
int n, k, a[40],c[40],maxj=0;

void dfs(int p, int b, int e) {
    if (p == k) {
        a[p]=e;
        int s=1;
        for (int i = 1; i <=k ; ++i) {
            s*=a[i];
        }
        if(s>maxj){
            maxj=s;
            for (int i = 1; i <= k; ++i) {
                c[i]=a[i];
            }
        }
        return;
    }
    for (int i = b; i <= e; ++i) {
        a[p]=i;
        if (i <= e - i) dfs(p + 1, i, e - i);
    }
}

int main() {
    cin >> n >> k;
    dfs(1, 1, n);
    for (int i = 1; i <=k; ++i) {
        if(i==1) cout<<c[i];
        else cout<<'*'<<c[i];
    }
    cout<<'='<<maxj;
    return 0;
}
