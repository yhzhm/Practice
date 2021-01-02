#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
char a[N][N];
int n;
bool col[N], d[N * 2], bd[N * 2];

void dfs(int u)
{
    if (u == n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << a[i][j];
            cout << endl;
        }
        cout << endl;

    }

    for (int i = 0; i < n; ++i) {
        if (!col[i] && !d[u - i + n] && !bd[u + i]) {
            a[u][i] = 'Q';
            col[i] = d[u - i + n] = bd[u + i] = true;
            dfs(u + 1);
            col[i] = d[u - i + n] = bd[u + i] = false;
            a[u][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    memset(a, '.', sizeof a);
    dfs(0);
    return 0;
}

/*
/ i + j
\ i - j + n
 */