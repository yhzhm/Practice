#include <iostream>
using namespace std;
const int N = 100010;
int a[N], b[N], n;
long long cnt;

void merge(int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge(l, mid), merge(mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (j > r || i <= mid && a[i] <= a[j]) b[k] = a[i++];
        else b[k] = a[j++], cnt += mid - i + 1;
    }
    for (int i = l; i <= r; ++i) a[i] = b[i];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    merge(0, n - 1);
    cout << cnt << endl;

    return 0;
}