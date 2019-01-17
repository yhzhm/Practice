// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
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
	int x = pow(10, n - 1);
	int y = pow(10, n);
	set<int> st;
	set<int>::iterator it;
	for (int i = x; i < y; ++i) {
		if (isp(i) && pd(i)) {
			st.insert(i);
		}
	}
	cout << st.size() << endl;
	for (it = st.begin(); it != st.end(); ++it) {
		cout << *it << ' ';
	}
	return 0;
}