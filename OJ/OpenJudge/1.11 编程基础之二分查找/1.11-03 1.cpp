//计数的变量要用long long类型 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r;
	cin >> r;
	int a[r + 1]={0};
	int n;
	cin >> n;
	int x, y, w, h, i;
	long long sum = 0, count = 0;
	for (i = 1; i <= n; ++i) {
		cin >> x >> y >> w >> h;
		for (int j = x + 1; j <= x + w; j++) {
			a[j] += h;
			sum += h;
		}
	}
	long long z = sum, d;
	for (i = 1; i <= r; ++i) {
		count += a[i];
		d = abs(sum-2*count);
		if(d <= z){
			z = d;
		}else break;
	}
	cout << i-1 << endl;
	return 0;
}
