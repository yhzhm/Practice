/*
 * 洛谷P1249 最大乘积
 * 题目描述

一个正整数一般可以分为几个互不相同的自然数的和，如3=1+2，4=1+3，5＝1+4=2+3，6=1+5＝2+4，…。

现在你的任务是将指定的正整数n分解成若干个互不相同的自然数的和，且使这些自然数的乘积最大。

输入输出格式

输入格式：
只一个正整数n，(3≤n≤10000)。

输出格式：
第一行是分解方案，相邻的数之间用一个空格分开，并且按由小到大的顺序。

第二行是最大的乘积。

输入输出样例

输入样例#1：
10
输出样例#1：
2 3 5
30*/

// 这题也是求最大乘积，要求输出分解方案和最大乘积

/*这道题的方法：贪心+高精度
首先可以通过运算得出：
n(n+1)>(n-1)(n+2)
再将几个数拆分可以看出基本上是连续自然数
所以就得出了这个结论
将一个数拆分成2+...+x   若a[x]<=a[x-1]  那么就将最后一个
数的值往前分配，一次分配1，直至全部分配完
但是数字有10000，所以必须用高精度*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,lena,lenb,lenc;
int ans=0;
int an[10005];   //存答案拆分数
char b[10005];
char a[10005];
char c[10005];
long long best;
void  cheng(){
    int x=0;
    lenc=0;
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            c[i+j-1]=c[i+j-1]+a[i]*b[j];
            c[i+j]=c[i+j]+c[i+j-1]/10;
            c[i+j-1]%=10;
        }
    }
    if(c[lena+lenb]!=0)lenc=lena+lenb;
    else lenc=lena+lenb-1;
    for(int i=1;i<=lenc;i++){
        a[i]=c[i];
        c[i]=0;
    }
    lena=lenc;
}    //高精度乘法
void divide(){
    int i=2;
    while(n>0){
        if(n<=i)an[i-1]=n;
        else
            an[i-1]=i;
        n=n-i;
        i++;
    }
    i-=2;
    if(an[i]<=an[i-1]){
        int w=i;
        while(an[i]!=0){
            w--;
            if(w==0)w=i-1;
            an[w]++;
            an[i]--;
        }
        i--;
    }            //将自然数拆分
    ans=i;
    a[1]=an[1];
    lena=1;
    for(int j=2;j<=i;j++){
        int k=an[j];
        int l=0;
        while(k!=0){
            l++;
            b[l]=k%10;
            k=k/10;
        }
        lenb=l;
        cheng();
    }
}
int main(){
    scanf("%d",&n);
    if(n==1){
        printf("1\n");
        printf("1");
        return 0;
    }
    else if(n==2){
        printf("2\n");
        printf("2");
        return 0;
    }
    else if(n==3){
        printf("3\n");
        printf("3");
        return 0;
    }
    else if(n==4){
        printf("4\n");
        printf("4");
        return 0;
    }
    divide();
    for(int i=1;i<=ans;i++)
        printf("%d ",an[i]);
    printf("\n");
    for(int i=lena;i>=1;i--)
        printf("%d",a[i]);
    return 0;
}
