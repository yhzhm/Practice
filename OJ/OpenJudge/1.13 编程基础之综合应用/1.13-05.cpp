#include<bits/stdc++.h>
using namespace std;
bool isp(int n)
{
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0)return false;
	}
	return true;
}
bool ish(int n)
{
	int s = 0, x = n;
	while (x > 0) {
		s = s * 10 + x % 10;
		x /= 10;
	}
	return s == n;
}
int main()
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 11; i <= n; ++i) {
		if (isp(i) && ish(i)) cnt++;
	}
	cout << cnt << endl;
	return 0;
}