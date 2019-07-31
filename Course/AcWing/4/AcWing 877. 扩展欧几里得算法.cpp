#include <iostream>
using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n --) {
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}
/*
对于不完全为 0 的非负整数 a，b，gcd（a，b）表示 a，b 的最大公约数，
必然存在非零整数对 x，y ，使得 gcd（a，b）=ax+by。

证明：设 a>b。
1，显然当 b=0，gcd（a，b）=a。此时 x=1，y=0；
2，ab!=0 时
设 ax1+by1=gcd(a,b);
   bx2+(a mod b)y2=gcd(b,a mod b);
根据朴素的欧几里德原理有 gcd(a,b)=gcd(b,a mod b);
则:ax1+by1=bx2+(a mod b)y2;
即:ax1+by1=bx2+(a-(a/b)*b)y2=ay2+bx2-(a/b)*by2
                            =ay2+b(x2-(a/b)*y2);

根据恒等定理得：x1=y2; y1=x2-(a/b)*y2;

==*==这样我们就得到了求解 x1,y1 的方法：x1，y1 的值基于 x2，y2.==*==

上面的思想是以递归定义的，因为 gcd 不断的递归求解一定会有个时候 b=0，所以递归可以结束。
int exgcd(int a,int b,int &x,int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x = y;
    y = t - a / b * y;
    return d;
}

or

int exgcd(int a, int b, int &x, int &y)
{
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    swap(x, y);
    y = y - a / b * x;
    return d;
}

==================================

递归exgcd(b, a % b, y, x);
b * y + (a mod b) * x = d
b * y + (a - a / b * b) * x = d
a * x + b * (y - a / b * x) = d = a * x + b * y
a的系数不变为x，
b的系数变为： y = y - a / b * x

==================================
解x, y不唯一:
ax0 + by0 = d
等价于=>  a(x0 - b/d) + b(y0 + a/d) = d
故所有解的形式为：
x = x0 - b/d*k
y = y0 + b/d*k
k为整数
 */