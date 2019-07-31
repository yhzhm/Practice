#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100010, mod = 1e9 + 7;
int fact[N], infact[N];

int qmi(int a, int k, int p)
{
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }

    int n; scanf("%d", &n);
    while (n --) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);//及时取模，3个int相乘会溢出long long
    }
    return 0;
}

/*
公式法 C(a, b) = a! / (b! * (a - b)!)
预处理出阶乘和逆元阶乘，因为m为质数，所以可以用快速幂求逆元
 */