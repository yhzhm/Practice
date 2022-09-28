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
        while(tt > 0 && h[q[tt]] < h[i])
        {
            res += (h[q[tt]] - last)
        }
    }
}