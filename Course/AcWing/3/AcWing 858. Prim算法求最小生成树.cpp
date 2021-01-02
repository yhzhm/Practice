#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int dist[N], n, m;
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; ++j) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();
    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}