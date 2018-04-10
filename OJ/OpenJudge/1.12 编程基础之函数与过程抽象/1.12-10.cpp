#include<bits/stdc++.h>
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
	int n;
	bool flag = 0;
	scanf("%d", &n);
	for (int i = 2; i <= n - 2; ++i) {
		if (isp(i) && isp(i + 2)) {
			printf("%d %d\n", i, i + 2);
			flag = 1;
		}
	}
	if (!flag) printf("empty");
	return 0;
}
