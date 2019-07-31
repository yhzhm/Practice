#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;
int n, m;
char a[N][15], b[15];
int f[15][15];

bool calc(char a[], int k)
{
    memset(f, 0, sizeof f);
    int lena = strlen(a + 1), lenb = strlen(b + 1);
    for (int i = 0; i <= lena; ++i) f[i][0] = i;
    for (int j = 0; j <= lenb; ++j) f[0][j] = j;

    for (int i = 1; i <= lena; ++i)
        for (int j = 1; j <= lenb; ++j)
            if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
            else f[i][j] = min(f[i - 1][j], f[i][j - 1]),
                               f[i][j] = min(f[i][j], f[i - 1][j - 1]) + 1;
    return k >= f[lena][lenb];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);

    while (m --)
    {
        int k;
        scanf("%s%d", b + 1, &k);
        int res = 0;
        for (int i = 1; i <= n; ++i)
            if (calc(a[i], k)) res ++;
        printf("%d\n", res);
    }
    return 0;
}
