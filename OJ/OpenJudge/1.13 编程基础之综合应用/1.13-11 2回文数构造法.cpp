// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000000;
bool a[MAXN];
bool isp(int n)
{
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}
bool pd(int n)
{
	int x = n, s = 0;
	while (x > 0) {
		s = s * 10 + x % 10;
		x /= 10;
	}
	return s == n;
}
int main()
{
	int n;
	cin >> n;
	if (n == 2) {cout << 1 << endl; cout << 11 << endl; return 0;}
	if (n % 2 == 0) {cout << 0 << endl; return 0;}
	int x = pow(10, n - 1);
	int y = pow(10, n);
	erat(y);
	set<int> st;
	set<int>::iterator it;
	for (int i = x; i < y; ++i) {
		if (a[i] && pd(i) ) {
			st.insert(i);
		}
	}
	cout << st.size() << endl;
	for (it = st.begin(); it != st.end(); ++it) {
		printf("%d ", *it);
	}
	return 0;
}