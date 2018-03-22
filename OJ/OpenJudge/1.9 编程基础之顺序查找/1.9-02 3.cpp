#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector< pair<int, string> > v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), greater< pair<int, string> >());
	cout << v.begin()->second << endl;
	return 0;
}