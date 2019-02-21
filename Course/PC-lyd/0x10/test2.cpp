#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
const ll M = 1e9;
ll a[60004], l, sum[120004];
int n;
void g(int b, int f)
{
	for (int j = 2; j * j <= b && b != 1; j++)
		while (b % j == 0)
		{
			sum[j] += f;
			b /= j;
		}
	if (b)
		sum[b] += f;
}
void h(ll c)
{
	fir(i, 1, l)
	a[i] *= c;
	fir(i, 1, l)
	a[i + 1] += a[i] / M, a[i] %= M;
	while (a[l + 1])
		++l;
}
int main()
{
	a[1] = 1, l = 1; cin >> n;
	fir(i, 1, n)
	g(n + i, 1);
	fir(i, 2, n + 1)
	g(i, -1);
	fir(i, 2, 2 * n)
	for (ll j = 0; j < sum[i]; ++j)
		h(i);
	cout << a[l];
	for (ll i = l - 1; i; --i)
		printf("%09lld", a[i]);
	return 0;
}
