#include <iostream>
using namespace std;
const int M = 2e5 + 10;
int n, m, q;
char a[M], b[M];
int Next[M], f[M];

int main()
{
    cin >> n >> m >> q;
    scanf("%s%s", a + 1, b + 1);

    for (int i = 2, j = 0; i <= m; ++i) {
        while (j && b[i] != b[j + 1]) j = Next[j];
        if (b[i] == b[j + 1]) j++;
        Next[i] = j;
    }

    for (int i = 1, j = 0; i <= n; ++i) {
        while (j && a[i] != b[j + 1]) j = Next[j];
        if (a[i] == b[j + 1]) j++;
        f[j]++;
    }

    for (int i = m; i; --i) f[Next[i]] += f[i];

    while (q --) {
        int x; cin >> x;
        cout << f[x] - f[x + 1] << endl;
    }
    return 0;
}
