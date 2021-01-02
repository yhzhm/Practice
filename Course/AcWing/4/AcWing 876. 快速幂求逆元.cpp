#include <iostream>
using namespace std;
typedef long long LL;

LL qmi(int a, int b, int p)
{
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n; cin >> n;
    while (n --) {
        int a, p;
        cin >> a >> p;
        if (a % p == 0) puts("impossible");
        else cout << qmi(a, p - 2, p) << endl;
    }
    return 0;
}

/*
欧拉函数φ(n)：
1~n中和n互质的数的个数
当n为质数时，φ(n) = n - 1

欧拉定理：
若a与n互质，则a ^ φ(n) ≡ 1 (mod n)

费马定理：（欧拉定理的一个特例）
当n是质数时，φ(n) = n - 1
若a与n互质，则a ^ φ(n) ≡ 1 (mod n)
即a ^ (n - 1) ≡ 1 (mod n)

乘法逆元：b的乘法逆元x
a / b ≡ a * x (mod n)
两边同乘b可得 a ≡ a * b * x (mod n)
即 1 ≡ b * x (mod n)
同 b * x ≡ 1 (mod n)
由费马定理可知，当n为质数时
b ^ (n - 1) ≡ 1 (mod n)
拆一个b出来可得 b * b ^ (n - 2) ≡ 1 (mod n)
故当n为质数时，b的乘法逆元 x = b ^ (n - 2)


 */