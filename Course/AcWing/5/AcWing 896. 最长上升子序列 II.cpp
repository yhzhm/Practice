#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010, INF = 2e9;
int n;
int a[N], f[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	fill(f, f + n, INF);
	for (int i = 0; i < n; ++i)
		*lower_bound(f, f + n, a[i]) = a[i];
	printf("%d\n", lower_bound(f, f + n, INF) - f);
	return 0;
}
