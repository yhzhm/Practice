/*2019: 【基础】最大乘积
时间限制 : 1 Sec内存限制 : 32 Mb提交 : 454解决 : 154
题目描述
将给出的一个正整数X（3≤X≤5000）分成任意个不相同的正整数，使得分成的这任意个正整数的和正好等于X、并且每个数均不相同，同时还要满足这分成的任意个正整数的乘积最大。
例如：X=9 时 
9=1+8 1 ╳ 8 =8
=2+7 2 ╳ 7=14
=... ...
=... ...
=1+2+6 1 ╳ 2 ╳ 6=12
=2+3+4 2 ╳ 3 ╳ 4=24
=... ...
列举出所有可能的分解之后，得到的最大乘积为 24，其数字之和为6
 
输入
一个整数N
 
输出
一个整数（即合理分解中的最大乘积的数字之和）。
 
样例输入 [复制]
9
样例输出 [复制]
6
提示[+]
*** 提示已隐藏，点击上方 [+] 可显示 ***
来源
2011年江苏省小学生信息学（计算机）奥赛*/

//
// Created by Hz Yang on 2017/6/7.
//
#include <iostream>
#include <cstring>

using namespace std;
int jc(long long  n,long long  x)//高精度乘法
{
    long long i,j,a[100005],lena,sum=0;
    memset(a,0,sizeof(a)) ;
    a[1]=1;lena=1;
    for(i=1;i<=n;i++){
        if(i==x) continue;
        if(x==2 && i==n) i++;
        for(j=1;j<=lena;j++)
            a[j]*=i;
        for(j=1;j<=lena;j++){
            a[j+1]+=a[j]/10;
            a[j]%=10;
        }
        while(a[lena+1]>0){
            lena++;
            a[lena+1]+=a[lena]/10;
            a[lena]%=10;
        }
    }
    for(i=lena;i>=1;i--)
        sum+=a[i];
    return sum;
}

int main() {
    long long  n,i,j,sum=0,x=0;
    cin >> n;
    for ( i = 2; i < n; ++i ) {
        sum+=i;
        if(sum>=n) break;
    }
    if(sum-n==1) x=2;
    else x=sum-n;
    cout << jc(i,x);
    return 0;
}

/*如果分解为可以是相等的自然数的和，那么分解的答案是m个3和一个2，即最大乘积是3^m*2或者是m个3和一个4，即最大乘积是3^m*4的形式

3*3>2*2*2，最后如果有三个2，要换成两个3，这样乘积才会最大

如 10 / \ 5 5 /\ /\ 2 3 2 3

如果把1993分拆成若干个互不相等的自然数的和的分法只有有限种，因而一定存在一种分法，使得这些自然数的乘积最大。

若1作因数，则显然乘积不会最大。把1993分拆成若干个互不相等的自然数的和，因数个数越多，乘积越大。为了使因数个数尽可能地多，我们把1993分成2+3…+n直到和大于等于1993。

若和比1993大1，则因数个数至少减少1个，为了使乘积最大，应去掉最小的2，并将最后一个数（最大）加上1。

若和比1993大k（k≠1），则去掉等于k的那个数，便可使乘积最大。

2+3+4+....+62＝1952<1993;

2+3+4+....+63＝2015>1993；

所以n=63。因为2015-1993=22，所以应去掉22，把1993分

（2+3+…+21）+（23+24+…+63）

这样下来积是最大的

2×3×…×21×23×24×…×63。

样例中的10也是这样

2+3+4=9<10

2+3+4+5=14>10

14-10=4

故去掉4

所以为2*3*5

算积要用高精*/
