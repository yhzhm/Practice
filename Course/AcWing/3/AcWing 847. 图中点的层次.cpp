#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010, M = N * 2;
int e[N], h[M], ne[M], idx;
int q[N], d[N], n, m; //q[]队列 d[]距离（层数）
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int u)
{
    int hh = 0, tt = -1;
    st[u] = true; d[u] = 0;
    q[++tt] = u;
    while (hh <= tt ) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) { //可以省去st[],改为直接判断d[j] == -1
                q[++tt] = j;
                st[j] = true;
                d[j] = d[t] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    bfs(1);
    cout << d[n] << endl;
    return 0;
}

/*
BFS
手写queue
 */