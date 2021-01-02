#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1000010;

int primes[N], cnt;
int euler[N];
bool st[N];

void get_eulers(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
            euler[i] = i - 1; //质数i的欧拉函数为i - 1
        }
        for (int j = 0; primes[j] <= n / i; ++j) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    int n; cin >> n;
    get_eulers(n);

    LL res = 0;
    for (int i = 1; i <= n; ++i) res += euler[i];

    cout << res << endl;
    return 0;
}
/*
在线性筛素数的过程中，求欧拉函数
1.i是质数，φ(i) = i - 1;
2.i % pj == 0，说明φ(i)中已包含pj因子，
φ(pj * i) = pj * i * [(1 - 1/p1)*(1 - 1/p2)*...*(1 - 1/pk)] = φ(i) * pj
3.i % pj != 0时
φ(pj * i) = pj * i * [(1 - 1/p1)*(1 - 1/p2)*...*(1 - 1/pk)] *(1 - 1/pj) = φ(i) * pj * (1 - 1/pj) = φ(i) * (pj - 1)


 */