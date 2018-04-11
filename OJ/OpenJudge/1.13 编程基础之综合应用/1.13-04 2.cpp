#include<bits/stdc++.h>
using namespace std;
int cnt[128] = {0}, maxn = 0;
void count(string &s)
{
	string::size_type i;
	for (i = 0; i < s.size(); ++i) {
		if (isupper(s[i])) cnt[(int)s[i]]++;
	}
}
int main()
{
	string s; char x;
	for (int i = 1; i <= 4; ++i) {
		getline(cin, s);
		count(s);
	}
	for (int i = 65; i <= 90; ++i) {//不在统计时找最大值，减少比较次数
		maxn = max(cnt[i], maxn);
	}
	for (int i = maxn; i >= 1; --i) {
		for (int j = 65; j <= 90; ++j) {
			x = (cnt[j] >= i) ? '*' : ' ';
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