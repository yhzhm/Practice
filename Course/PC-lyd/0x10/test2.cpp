#include<bits/stdc++.h>
using namespace std;
vector<int> dp[105][105];
int a[105][105];
vector<int> plusy(vector<int> a, vector<int> b)
{
	vector<int> c;
	int t = 0;
	int maxsize = max(a.size(), b.size());
	for (int i = 0; i < maxsize; ++i) {
		if (i < a.size()) t += a[i];
		if (i < b.size()) t += b[i];
		t += a[i] + b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	while (t) {
		c.push_back(t % 10); t /= 10;
	}
	return c;
}
void aaa(vector<int> a) {
	if (a.size() == 0) {
		cout << 0;
		return;
	}
	for (int i = a.size() - 1; i >= 0; --i) {
		cout << a[i];
	}
	cout << endl;
}
int main()
{
//	freopen("move.in","r",stdin);
//	freopen("move.out","w",stdout);
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	dp[1][1] = vector<int>(1, 1);
	for (int i = 1; i <= m; ++i) {
		if (a[i][1] == 1) break;
		dp[i][1] = vector<int>(1, 1);
	}
	for (int i = 1; i <= n; ++i) {
		if (a[1][i] == 1) break;
		dp[1][i] = vector<int>(1, 1);
	}
	for (int i = 2; i <= m; ++i) {
		for (int j = 2; j <= n; ++j) {
			if (a[i][j] == 0)
				dp[i][j] = plusy(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	aaa(dp[m][n]);
	fclose(stdin); fclose(stdout);
	return 0;
}
