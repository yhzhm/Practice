#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx;
int q[N], d[N], st[N], n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0) q[++tt] = i;
    }
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (d[j] == 0) q[++tt] = j;
        }
    }
    return tt == n - 1;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    if (topsort()) {
        for (int i = 0; i < n; ++i) cout << q[i] << ' ';
        cout << endl;
    } else puts("-1");
}