//扩展欧几里得求乘法逆元
#include <iostream>
using namespace std;
typedef long long LL;
int n;

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
    cin >> n;
    while (n --)
    {
        int a, p, x, y;
        // if (a < p) swap(a, p);
        cin >>  a >> p;
        int d = exgcd(a, p, x, y);
        if (d == 1) cout << ((LL)x + p) % p << endl;
        else puts("impossible");

    }
    return 0;
}

/*
当n为质数时，b的乘法逆元 x = b ^ (n - 2)

当n不是质数时，用扩展欧几里得算法求逆元：
b有逆元的充要条件是b与n互质，所以gcd(b, n) = 1
假设b的逆元为x，那么有b * x ≡ 1 (mod n)
等价：bx + ny = 1
exgcd(b, n, x, y)
 */