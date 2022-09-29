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
        while(tt >= 0 && h[q[tt]] < h[i])
        {
            int top = q[tt --];
            if (tt < 0) break;
            res += (min(h[q[tt]], h[i]) - h[top])* (i - q[tt] - 1);
        }
        q[++ tt] = i;
    }
    cout << res << endl;
    return 0;
}