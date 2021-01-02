#include <iostream>
using namespace std;

void div(int x)
{
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) x /= i, cnt ++;
            cout << i << ' ' << cnt << endl;
        }
    }
    if (x > 1) cout << x << ' ' << 1 << endl; //n中最多只包含一个大于√n 的质因子
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int x;
        cin >> x;
        div(x);
    }
    return 0;
}

/*
分解质因数——试除法
O(logn)~ O(sqrt(n))

从小到大尝试n的所有因数。

n中最多只包含一个大于√n 的质因子

 */