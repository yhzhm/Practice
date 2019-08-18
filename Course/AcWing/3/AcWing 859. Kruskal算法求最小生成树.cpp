#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, m, res, cnt;
int p[N];
struct node {
    int a, b, w;
    bool operator < (const node &W) const {
        return w < W.w;
    }
} edges[N * 2];

int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    sort(edges, edges + m);
    for (int i = 1; i <= n; ++i) p[i] = i;

    for (int i = 0; i < m; ++i) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt ++;
        }
    }

    if (cnt < n - 1) puts("impossible");
    else printf("%d\n", res);

    return 0;
}