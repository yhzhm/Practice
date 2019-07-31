#include <iostream>
using namespace std;
const int N = 310;
int n;
int s[N];//前缀和
int f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &s[i]), s[i] += s[i - 1];

    for (int len = 2; len <= n; ++len)//枚举区间长度
        for (int i = 1; i + len - 1 <= n; ++i)//枚举起点
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1e9;
            for (int k = l; k < r; ++k)//枚举合并分界线
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
    printf("%d\n", f[1][n]);
    return 0;
}