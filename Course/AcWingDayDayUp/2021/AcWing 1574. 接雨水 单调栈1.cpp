#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], q[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> h[i];

    int res = 0;
    int tt = -1;

    for (int i = 0; i < n; ++i)
    {
        int last = 0;
        while(tt >= 0 && h[q[tt]] < h[i])
        {
            res += (h[q[tt]] - last) * (i - q[tt] - 1);
            last = h[q[tt]];
            tt --;
        }
        if (tt >= 0) res += (h[i] - last) * (i - q[tt] - 1);
        q[++ tt] = i;
    }
    cout << res << endl;
    return 0;
}