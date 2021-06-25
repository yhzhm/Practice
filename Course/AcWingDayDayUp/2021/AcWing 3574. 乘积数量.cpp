// Created by Hz Yang on 2021.05
#include <iostream>
using namespace std;

typedef long long LL;
int main()
{
	int n;
	scanf("%d", &n);
	LL ans = 0, sum = n * (n + 1) / 2;
	int sp = 1, sn = 0, s = 1;
	while (n --)
	{
		int a;
		scanf("%d", &a);
		if (a < 0) s *= -1;
		if (s > 0) ans += sp, sp ++;
		else ans += sn, sn ++;
	}
	printf("%lld %lld\n", sum - ans, ans);
	return 0;
}