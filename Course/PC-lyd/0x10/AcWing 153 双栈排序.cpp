#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 1010;

int n;
int a[N], minv[N];//minv[i]:存储i~n区间内的最小值
bool g[N][N];//邻接矩阵存图
int color[N];//二分图染色

bool dfs(int u, int c)//染色函数
{
    color[u] = c;
    for (int i = 1; i <= n; i ++ )
        if (g[u][i])//当前两点有边
        {
            if (color[i] == c) return false;//颜色相同，不合法
            if (color[i] == -1 && !dfs(i, !c)) return false;//未染过色，染色
        }

    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        minv[n + 1] = n + 1;//边界
        for (int i = n; i; i -- ) minv[i] = min(minv[i + 1], a[i]);

        memset(g, false, sizeof g);
        for (int i = 1; i <= n; i ++ )
            for (int j = i + 1; j <= n; j ++ )
                if (a[i] < a[j] && minv[j + 1] < a[i])//不能入同一栈<==>a[k]<a[i]<a[j](i<j<k)
                    g[i][j] = g[j][i] = true;//二分

        memset(color, -1, sizeof color);
        bool flag = true;
        for (int i = 1; i <= n; i ++ )//为了保证字典序小，尽量分给第一个栈
            if (color[i] == -1)//如果颜色未初始化过，染色
                if (!dfs(i, 0))
                {
                    flag = false;
                    break;
                }

        if (!flag)//染色不成功，输出0
        {
            cout << 0 << endl;
            continue;
        }

        stack<int> stk1, stk2;//用两个栈模拟
        int now = 1;
        for (int i = 1; i <= n; i ++ )
        {
            if (color[i] == 0)//若当前颜色为0，入第一个栈
            {
                stk1.push(a[i]);
                cout << "a ";
            }
            else//否则入第二个栈
            {
                stk2.push(a[i]);
                cout << "c ";
            }

            while (true)//每次判断栈顶是否可以弹出
            {
                if (stk1.size() && stk1.top() == now)
                {
                    stk1.pop();
                    cout << "b ";
                    now ++ ;
                }
                else if (stk2.size() && stk2.top() == now)
                {
                    stk2.pop();
                    cout << "d ";
                    now ++ ;
                }
                else break;
            }
        }
        cout << endl;
    }

    return 0;
}
