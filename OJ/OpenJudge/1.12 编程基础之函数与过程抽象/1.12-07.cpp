#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m, n, x, sum = 0;
	cin >> m >> n;
	queue<int> q;
	set<int> s;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (s.find(x) == s.end()) {
			s.insert(x);
			q.push(x);
			sum++;
			if (s.size() > m) {
				s.erase(q.front());
				q.pop();
			}
		}
	}
	cout << sum << endl;
	return 0;
}
