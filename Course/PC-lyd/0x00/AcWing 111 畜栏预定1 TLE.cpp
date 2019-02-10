// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int MAX = 50010;
struct node
{
	int st, ed, id;
	bool operator < (const node &b) const {
		if (this->st == b.st)return this->id < b.id;
		return this->st < b.st;
	}
} a[MAX];
int s[MAX], b[MAX];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)	{
		cin >> a[i].st >> a[i].ed;
		a[i].id = i + 1;
	}
	sort(a, a + n);
	int sum = 0;
	s[sum] = a[0].ed;
	b[a[0].id] = sum++;
	for (int i = 1; i < n; ++i) {
		bool flag = 1;
		for (int j = 0; j < sum; ++j) {
			if (a[i].st > s[j]) {
				s[j] = a[i].ed;
				b[a[i].id] = j;
				flag = 0;
				break;
			}
		}
		if (flag) {
			s[sum] = a[i].ed;
			b[a[i].id] = sum;
			sum++;
		}
		// for (int j = 0; j < sum; ++j) cout << s[j] << ' ';
		// cout << endl;
	}
	cout << sum << endl;
	for (int i = 1; i <= n; ++i) cout << b[i] + 1 << endl;
	return 0;
}