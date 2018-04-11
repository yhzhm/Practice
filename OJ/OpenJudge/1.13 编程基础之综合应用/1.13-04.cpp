#include<bits/stdc++.h>
using namespace std;
int cnt[128] = {0}, maxn = 0;
void count(string &s)
{
	for (int i = 0; i < s.size(); ++i) {
		if (isupper(s[i])) cnt[s[i]]++;
		maxn = max(cnt[s[i]], maxn);
	}
}
int main()
{
	string s;
	for (int i = 1; i <= 4; ++i) {
		getline(cin, s);
		count(s);
	}
	for (int i = maxn; i >= 1; --i) {
		for (int j = 65; j <= 90; ++j) {
			char x = (cnt[j] >= i) ? '*' : ' ';
			cout << x << ' ';
		}
		cout << endl;
	}
	for (int i = 65; i <= 90; ++i) {
		cout << (char)i << ' ';
	}
	cout << endl;
	return 0;
}