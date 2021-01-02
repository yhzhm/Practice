#include <iostream>
using namespace std;

bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    int n, x;
    cin >> n;
    while (n --) {
        cin >> x;
        if (is_prime(x)) puts("Yes");
        else puts("No");
    }
    return 0;
}

/*
质数的判定——试除法（根据质数的定义判定）O(sqrt(n))
i <= sqrt(n) ,每次执行开根号函数，效率低
i * i <= n,  i * i存在溢出风险
i <= n / i, 没有溢出风险
 */