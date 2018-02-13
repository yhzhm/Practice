//
// Created by Hz Yang on 2017/6/15.
// BFS 注意：1.读入数据没有空格 2.用读入整数再拆解法的话，要用long long 类型
#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;
const int INF = 100000000;//INF过大可能会有溢出风险，一般讲INF设为放大2~4倍也不会溢出的大小
typedef pair<int, int> P;//pair表示状态（坐标），用typedef自定义类型，简洁定义语句
int n, a[45][45], d[45][45];//a[][]表示迷宫，d[][]记录到各个位置的最短距离
//int N,M;                  //数组大小
//int sx,sy;                //起点坐标
//int gx,gy;                //终点坐标
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};//四个方向的移动量

//求从起点到终点的最短距离，如果无法到达，则是INF。
int bfs() {
    queue<P> que;//队列类型为P的队列que
    for (int i = 1; i <= n; ++i) {//将所有位置的距离都初始化为INF
        for (int j = 1; j <= n; ++j) {
            d[i][j] = INF;
        }
    }
    //将起点加入队列，并将这一位置的距离设为1
    que.push(P(1, 1));
    d[1][1] = 1;
    //不断循环，只到队列的长度为0
    while (que.size()) {
        //从队列的最前端取出元素，存入P类型的变量p
        P p = que.front();
        que.pop();//最前端元素离队
        if (p.first == n && p.second == n) break;//如果取出的位置是终点，则结束搜索
        for (int i = 0; i < 4; ++i) {//四个方向的循环
            int nx = p.first + dx[i], ny = p.second + dy[i];//移动之后的位置记为(nx,ny)
            //判断是否可以移动以及是否已经访问过
            if (0 < nx && nx <= n && 0 < ny && ny <= n && a[nx][ny] == 0 && d[nx][ny] == INF) {
                que.push(P(nx, ny));//可以移动的话，将位置坐标加入队列，并且到该位置的距离确定为到p的距离+1
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[n][n];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        long long x;//输入数据没有空格，读入后再拆分
        cin >> x;
        for (int j = n; j >= 1; --j) {
            a[i][j] = x % 10;
            x /= 10;
        }
    }
//    for (int i = 1; i <= n; ++i) { //输入数据有空格的读入方法
//        for (int j = 1; j <= n; ++j) {
//            cin >> a[i][j];
//        }
//    }
    cout << n * n - bfs();
    return 0;
}


