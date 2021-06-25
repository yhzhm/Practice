#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;

int p[N], cnt;
bool st[N];

void init(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		if (!st[i]) p[cnt ++] = i;
		for (int j = 0; p[j] <= n / i; j ++)
		{
			st[p[j] * i] = true;
			if (i % p[j] == 0) break;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (auto x : p) cout << x << ' ';
	return 0;
}
