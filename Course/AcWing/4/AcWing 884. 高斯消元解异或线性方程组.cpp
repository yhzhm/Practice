#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

int n, a[N][N];

int gauss()
{
    int c, r;
    for (c = r = 0; c < n; ++c)
    {
        int t = r;
        for (int i = r; i < n; ++i) //找非零行
            if (a[i][c]) {t = i; break;}
        if (a[t][c] == 0) continue; //没找到

        for (int i = c; i < n + 1; ++i) swap(a[t][i], a[r][i]); //交换行

        for (int i = r + 1; i < n; ++i) //消元
            if (a[i][c])
                for (int j = n; j >= c; --j)
                    a[i][j] ^= a[r][j];

        r ++;
    }

    if (r < n)
    {
        for (int i = r; i < n; ++i)
            if (a[i][n]) return 2; //有矛盾，无解
        return 1; //无矛盾，有无穷多组解
    }

    for (int i = n - 1; i >= 0; --i) //求唯一解
        for (int j = i + 1; j < n; ++j)
            a[i][n] ^= a[j][n] & a[i][j];

    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n + 1; ++j)
            cin >> a[i][j];

    int res = gauss();

    if (!res)
        for (int i = 0; i < n; ++i) cout << a[i][n] << endl;
    else if (res == 1) puts("Multiple sets of solutions");
    else puts("No solution");

    return 0;
}