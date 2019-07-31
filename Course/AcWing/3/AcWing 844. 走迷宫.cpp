#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int M = 110;
int n, m, a[M][M], b[M][M]; //a存储地图 b记录走过的步数（层数）
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pii>q;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j], a[i][j] ^= 1; //01互换，1可走，0不可走，边界也是0，省去边界判断

    q.push({1, 1}); //初始状态入队列
    b[1][1] = 0;
    while (q.size()) {
        pii t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = t.first + dx[i], y = t.second + dy[i]; //计算下一步坐标
            if (a[x][y] == 1 && b[x][y] == 0) { //a判断是否可走，b判断是否走过
                b[x][y] = b[t.first][t.second] + 1; //记录步数（层数）
                q.push({x, y}); //下一层的点位置入队
            }
        }
    }

    cout << b[n][m]  << endl;

}

/*
BFS框架：
queue <- 初始状态
while  queue不空
{
    t  <- 队头
    拓展t加到队尾
}

 */