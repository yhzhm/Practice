#include <bits/stdc++.h>

using namespace std;
bool a[52][52];
char b[52][52];
int ans;

void dfs(int x, int y) {
    ans++;
    a[x][y] = false;
    if (a[x - 1][y]) dfs(x - 1, y);
    if (a[x][y + 1]) dfs(x, y + 1);
    if (a[x + 1][y]) dfs(x + 1, y);
    if (a[x][y - 1]) dfs(x, y - 1);
}

int main() {
//    freopen("tile.in", "r", stdin);
//    freopen("tile.out", "w", stdout);
    for (int i = 0; i < 52; ++i) {
        for (int j = 0; j < 52; ++j) {
            b[i][j] = '*';
        }

    }
    int h, w, bx, by;
    scanf("%d%d", &w, &h);
    char c;
    for (int i = 1; i <= h ; ++i) {
        for (int j = 1; j <= w+1 ; ++j) {
            scanf("%c", &c);
//			cin>>c;
            b[i][j] = c;
            if (c == '.') a[i][j] = true;
            else if (c == '@') {
                bx = i;
                by = j;
                a[i][j] = true;
            }
        }
//        scanf("*");
    }

    for (int i = 1; i <= h+1 ; ++i) {
        for (int j = 1; j <= w+1 ; ++j) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
//   cout<<':'<<(int)b[2][1]<<':'<<(int)b[2][w+1];

    dfs(bx, by);
    printf("%d\n", ans);
    return 0;
}