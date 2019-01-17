#include <iostream>
#include <algorithm>
using namespace std;
bool isp(int n)
{
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}
int main()
{
	int x, y, sum = 0;
	cin >> x >> y;
	if (x > y) swap(x, y);
	for (int i = x; i <= y; ++i) {
		if (isp(i) == 1) {
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}