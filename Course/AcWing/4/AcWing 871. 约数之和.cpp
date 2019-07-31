#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int M = 1e9 + 7;

int main()
{
    int n; cin >> n;
    unordered_map<int, int> primes;
    while (n --) {
        int x; cin >> x;
        for (int i = 2; i <= x / i; ++i)
            while (x % i == 0) x /= i, primes[i] ++;
        if (x > 1) primes[x] ++;
    }

    LL res = 1;
    for (auto prime : primes) {
        LL a = prime.first, b = prime.second, t = 1;
        while (b --) t = (t * a + 1) % M;
        res = (res * t) % M;
    }
    cout << res << endl;

    return 0;
}

/*
N = p1^a1×p2^a2…pk^ak
约数个数 = (a1 + 1)(a2 + 1)…(ak + 1)
每个质因子有0~a,共a + 1种选法
约数之和 = (p1^0 + p1^1 + … + p1^a1)…(pk^0 + pk^1 + … + pk^ak)
 */