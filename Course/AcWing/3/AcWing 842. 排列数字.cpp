#include <iostream>
using namespace std;

int n, p[10];
bool st[10];

void dfs(int u)
{
    if (u == n) {
        for (int i = 0; i < n; ++i) cout << p[i] << ' ';
        cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        if (st[i] == 0) {
            p[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);

    return 0;
}