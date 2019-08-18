#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510;
int g[N][N], dist[N], n, m; //g[][]邻接矩阵存储图，dist[i]1号点到i号点的距离
bool st[N]; //st[i]i号点到1号点的距离是否已确定（是否在集合s中）

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i < n; ++i) { //循环n-1次，找1号点以外的n-1个点
        int t = -1;  //用于寻找第一个不在集合s中的点
        for (int j = 1; j <= n; ++j) //找不在s中的距离最小的点
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        if (t == n) break; //优化，n号点确定最短距离即可终止
        st[t] = true;  //将t加入集合s
        for (int j = 1; j <= n; ++j)  //用t更新其它点的距离(g[t][]行，和t相关的点)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);  //存在重边，只保存最短的那条边
    }
    printf("%d\n", dijkstra());

    return 0;
}

/*
朴素Dijkstra算法：
集合s：当前已确定最短距离的点。
①dist[1] = 0, dist[i] = +∞;   dist[i]:点i到起始点的最短距离。
②for v : 1 ~ n
    t  <--不在s中的距离最小的点; (dist[i]最小)
    s  <-- t (将t加入集合s)
    用t更新其它点的距离(和t相连的点) j : 1 ~ n dist[j] = dist[t] + g[t][j]

 */