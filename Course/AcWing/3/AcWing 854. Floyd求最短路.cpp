#include <iostream>
#include <cstring>
using namespace std;
const int N = 210, INF = 1e9;
int g[N][N], n, m, k;

void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;

    while (m --) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = min(g[a][b], w);
    }

    floyd();

    while (k --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (g[a][b] > INF / 2) puts("impossible");
        else printf("%d\n", g[a][b]);
    }

    return 0;
}