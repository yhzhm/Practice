// Created by Hz Yang on 2019.04
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long LL;
using namespace std;
const int M = 120010, m = 1e9;//M:n的取值范围，m:压位位数9

int powers[M];//powers[]:保存质数出现的次数
int primes[M], cnt; //primes[]:保存筛到的质数
bool st[M];//用于筛质数

void get_primes(int n)//筛出质数 o(nlogn)
{
	for (int i = 2; i <= n; ++i)
		if (!st[i]) {
			primes[cnt++] = i;
			for (int j = i * 2; j <= n; j += i) st[j] = true;
		}
}

int get(int n, int p) //n的阶乘里有多少个因子p
{
	int s = 0;
	while (n) {
		s += n / p;
		n /= p;
	}
	return s;
}

void multi(vector<LL> &a, int b)//高精度乘法
{
	LL t = 0;
	for (int i = 0; i < a.size(); ++i) {
		a[i] = a[i] * b + t;
		t = a[i] / m;
		a[i] %= m;
	}
	while (t) a.push_back(t % m), t /= m;
}

void out(vector<LL> &a)
{
	printf("%lld", a.back());
	for (int i = a.size() - 2; i >= 0; --i) printf("%09lld", a[i]);
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	get_primes(n * 2);

	for (int i = 0; i < cnt; ++i) { //枚举每个质数,计算质数的个数
		int p = primes[i];
		powers[p] = get(n * 2, p) - get(n, p) * 2;
	}

	int k = n + 1; //处理除数n+1；
	for (int i = 0; i < cnt && primes[i] <= k; ++i) {
		int p = primes[i], s = 0;
		while (k % p == 0) s++, k /= p;
		powers[p] -= s;
	}

	vector<LL> res;
	res.push_back(1);
	//高精度乘法，将所有因数相乘
	for (int i = 2; i <= n * 2; ++i)
		for (int j = 0; j < powers[i]; ++j)
			multi(res, i);

	out(res);

	return 0;
}