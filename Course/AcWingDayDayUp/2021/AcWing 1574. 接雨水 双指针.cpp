#include <iostream>
using namespace std;
const int N = 100005;
int n, res, h[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> h[i];
    
    int l = 0, r = n - 1;
    int lmax = 0, rmax = 0;
    
    while(l < r)
    {
        lmax = max(lmax, h[l]);
        rmax = max(rmax, h[r]);
        if (lmax <= rmax)
            res += lmax - h[l ++];
        else
            res += rmax - h[r --];
    }
    
    cout << res << endl;
    return 0;
}