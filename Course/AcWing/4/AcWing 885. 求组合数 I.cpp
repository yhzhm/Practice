#include <iostream>
using namespace std;
const int N = 2010, mod = 1e9 + 7;
int n, c[N][N];

void init()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j)
            if (!j) c[i][j] = 1; //从i个苹果中选0个苹果的方案数为1
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}

int main()
{
    init();
    cin >> n;
    while (n --) {
        int a, b; cin >> a >> b;
        cout << c[a][b] << endl;
    }
    return 0;
}

/*
递推:
C(a, b) = C(a - 1, b) + C(a -1, b - 1)
 */