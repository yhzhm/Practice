#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;


const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
bool st[N];

int ans = N;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}


// 以u为根的子树中点的数量
int dfs(int u)
{
    st[u] = true; // 标记一下，已经被搜过了
    cout << endl << u << ':' << endl;
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            // cout << j << '-' << s << ' ';
            res = max(res, s);
            sum += s;
        }
    }

    cout << res << ":" << n - sum << "->";
    res = max(res, n - sum);
    cout << res << endl;
    ans = min(ans, res);
    return sum;
}


int main()
{
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}