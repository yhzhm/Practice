#include <iostream>
using namespace std;

int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; ++i)
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

int main()
{
    int n; cin >> n;
    while (n --)
    {
        int x; cin >> x;
        cout << phi(x) << endl;
    }
    return 0;
}

/*
欧拉函数：
定义：1~N中与N互质的数的个数被称为欧拉函数，记为φ(N)
若N = p1^a1 × p2^a2 × ... × pk^ak
则φ(N) = N * (p1 - 1) / p1 * (p2 - 1) / p2 * ... * (pk - 1) / pk


 */