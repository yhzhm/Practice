#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b) {
        x = 1, y = 0;
        return a;

    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n; cin >> n;
    bool flag = true;
    LL a1, m1; cin >> a1 >> m1;
    for (int i = 0; i < n - 1; ++i) {
        LL a2, m2, k1, k2;
        cin >> a2 >> m2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d) {
            flag = false;
            break;
        }
        k1 *= (m2 - m1) / d;
        LL t = a2 / d;
        k1 = (k1 % t + t) % t;//k1为方程的最小正整数解，k1 + k * a2 / d

        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);//最小公倍数
    }
    if (flag) cout << (m1 % a1 + a1) % a1 << endl;
    else puts("-1");

    return 0;
}

/*
题目没有要求mi两两互质，所以不能直接套用中国剩余定理公式

思路：不断将两个等式合并成一个等式，最后变成一个等式
x mod a1 = m1   =>    x = k1 * a1 + m1
x mod a2 = m2   =>    x = k2 * a2 + m2
两个等式合并可得：
k1 * a1 + m1 = k2 * a2 + m2
k1 * a1 - k2 * a2 = m2 - m1
有解等价于(a1, a2) | m2 - m1
k1, k2可用扩展欧几里得算法求出
解的形式为：
k1 + k * a2 / d
k2 + k * a1 / d

x = k1 * a1 + m1
  = (k1 + k * a2 / d) * a1 + m1
  = (a1 * k1 + m1) + k * (a1 * a2 / d)
  = (a1 * k1 + m1) + k * [a1, a2] //[a1, a2]为a1, a2的最小公倍数
等价于x = x0 + k * a0 的形式，可以和下一个等式继续合并
       ≈ m + k * a
直到剩下最后一个等式：
x = k * a + m
x mod a ≡ m
m mod a为最小解
 */