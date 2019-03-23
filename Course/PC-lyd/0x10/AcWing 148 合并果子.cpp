// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int main()
{
	int n, x, res = 0;
	cin >> n;
	priority_queue<int, vector<int> , greater<int>> q;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		q.push(x);
	}
	while (q.size() - 1) {
		x = 0;
		x += q.top(), q.pop();
		x += q.top(), q.pop();
		res += x, q.push(x);
	}
	cout << res << endl;
	return 0;
}