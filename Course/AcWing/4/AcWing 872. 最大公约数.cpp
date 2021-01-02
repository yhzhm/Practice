#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n; cin >> n;
	while (n --) {
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	}
	return 0;
}

/*
最大公约数：
欧几里得算法，也叫辗转相除法
d | a, d | b => d | ax + by
(a, b) = (b, a %b)
a % b = a - (a/b) * b = a - c * b

 */