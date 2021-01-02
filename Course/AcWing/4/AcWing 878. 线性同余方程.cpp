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
        int a, b, m, x, y;
        scanf("%d%d%d", &a, &b, &m);
        int d = exgcd(a, m, x, y);
        if (b % d) puts("impossible");
        else printf("%d\n", (long long) x * (b / d) % m);
    }
    return 0;
}

/*
a * x ≡ b(mod m)
等价于：a * x = m * y + b
a * x - m * y = b
a * x + m * (-y) = b
由扩展欧几里得可知，a * x0 + m * y0 = gcd(a, m) = d
1.若b不是d的倍数，则无解
2.若b是d的倍数，则x扩大(b / d)倍即为答案：x * (b / d)

 */