#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 100010;
typedef pair<int, int> pii;

int h[N], e[N], w[N], ne[N], idx;
int dist[N], n, m;
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap; //小根堆
    heap.push({0, 1}); //first:距离 second：点的编号

    while (heap.size()) {
        auto t = heap.top(); heap.pop(); //取堆顶
        int ver = t.second, distance = t.first; //ver:节点编号，distance：1号点到当前点的距离
        if (st[ver]) continue; //判断当前点是否已经在集合s中（是否已确定最短距离）
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) { //遍历和当前节点相连的所有节点
            int j = e[i];
            if (dist[j] > distance + w[i]) { //更新距离
                dist[j] = distance + w[i];
                heap.push({dist[j], j}); //有更新的节点入堆
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c); //算法保证会找到最短边，所以不需要处理重边
    }
    printf("%d\n", dijkstra());

    return 0;
}

/*
堆优化版Dijkstra
稀疏图，用领接表存储

 */