#include <iostream>
using namespace std;
typedef long long LL;
const int N = 20;

int n, m;
int p[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> p[i];

    int res = 0;
    for (int i = 1; i < 1 << m; ++i) { //二进制表示对应该位的质数选或不选
        int t = 1, cnt = 0;  //t所选质数的乘积，cnt共选了几个质数
        for (int j = 0; j < m; ++j) { //枚举每一个二进制位
            if (i >> j & 1) { //判断该位是否为1（是否选）
                cnt ++;  //统计选了几个
                if ((LL)t * p[j] <= n) { //计算所选质数的乘积
                    t *= p[j];
                } else {
                    t = -1;
                    break;
                }

            }
        }
        if (t != -1) { //容斥原理，奇数项加，偶数项减
            if (cnt % 2) res += n / t; //  n/t:1~n中能整除该种组合的数的个数
            else res -= n / t;
        }
    }
    cout << res << endl;
    return 0;
}

/*
容斥原理
 */