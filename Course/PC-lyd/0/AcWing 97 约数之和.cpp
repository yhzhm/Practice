// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
const int mod = 9901;
int qmi(int a, int k)//快速幂
{
	a %= mod;
	int res = 1;
	while (k) {
		if (k & 1) res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}
int sum(int p, int k)
{
	if (k == 0) return 1;
	//从p^0起，所以k为偶数时，有奇数项
	if (k % 2 == 0) return (p % mod * sum(p, k - 1) + 1) % mod;
	return (1 + qmi(p, k / 2 + 1)) * sum(p, k / 2) % mod;
}
int main()
{
	int A, B;
	cin >> A >> B;
	int res = 1;
	for (int i = 2; i <= A; ++i) {
		int s = 0;
		while (A % i == 0) {
			s++;
			A /= i;
		}
		if (s) res = res * sum(i, s * B) % mod;
	}
	if (!A) res = 0;
	cout << res << endl;
	return 0;
}
/*
题目求A^B的约数之和
A = p1^k1 * p2^k2 * ... * pn^kn
A^B = p1^k1B * p2^k2B * ... * pn^knB
将A分解质因数，就可得到A^B的质因数
求A有多少个约数：
p1有k1+1个选法，p2有k2+1个选法，所以共有选法
（k1 +1) * (k2+2) * ... * (kn + 1)
不同的约数之和：
(p1^0 + p1^1 + ... + p1^k1) * (p2^0 + p2^1 + ... + p2^k1) * ... * (pn^0 + pn^1 + ... + pn^k1)

sum(p,k) = p^0 + p^1 + ... + p^k
若有偶数项，可以分成两部分：
sum(p,k) = p^0 + p^1 + ... + p^k
		 = (p^0 + p^1 + ... + p^(k/2)) + (p^(k/2+1) + ... + p^k)
		 = (p^0 + p^1 + ... + p^(k/2)) + p^(k/2+1) * (p^0 + p^1 + ... + p^(k/2))
		 = (1+p^(k/2+1)) * (p^0 + p^1 + ... + p^(k/2))
		 = (1+p^(k/2+1)) * sum(p,k/2)
若有偶数项除以2，若有奇数项减1：
sum(p,k) = p^0 + p^1 + ... + p^k
		 = p^0 + p * (p^0 + ... + p^(k-1))
		 = p^0 + p * sum(p,k-1)
		 = 1 + p * sum(p,k-1)

 */