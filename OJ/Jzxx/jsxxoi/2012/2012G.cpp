/*2246: 【提高】堆木头
时间限制 : 10 Sec内存限制 : 32 Mb提交 : 694解决 : 222
题目描述
有n根木头(2<=n<=10^16 )，堆成k层(2≤k≤n)，要求下层木头数为上层木头数加1.
例如：n=6   
堆法有1种堆法。
n=9
堆法有，2种堆法。
n=4    不可能有符合条件的堆法。
输入
一个整数n
输出
一个整数，即堆法数，若不可能，则输出0。
样例输入 [复制]
21
样例输出 [复制]
3
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2012江苏省青少年信息学奥林匹克小学组竞赛复赛*/
//
// Created by Hz Yang on 2017/6/5.
//
#include<iostream>
using namespace std;
int main()
{
    int count=0;
    long long n,k,sum=0;
    cin>>n;
    for(k=1;k<=n;++k){
        sum+=k;
        if(n-sum<0) break;
        if((n-sum)%k==0) count++;
    }
    cout<<count;
    return 0;
}
