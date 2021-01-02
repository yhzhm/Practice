#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 100010;
int e[N], w[N], h[N], ne[N], idx;
int dist[N], cnt[N], n, m;
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa()
{
    // memset(dist, 0x3f, sizeof dist);
    // dist[1] = 0;

    queue<int> q;
    // q.push(1);  st[1] = true;
    for (int i = 1; i <= n; ++i) q.push(i), st[i] = true;

    while (q.size()) {
        int t = q.front();
        q.pop(); st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]) q.push(j), st[j] = true;
            }
        }
    }

    // if (dist[n] == 0x3f3f3f3f) return -1;
    // else return dist[n];
    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    if (spfa()) puts("Yes");
    else puts("No");

    return 0;
}
