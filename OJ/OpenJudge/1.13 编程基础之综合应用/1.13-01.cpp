#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void conversion(string s1, string &s2, int d1, int d2)
{
	ll n = 0, t;
	for (int i = 0; i < s1.size(); ++i) {
		if (isdigit(s1[i])) t = s1[i] - '0';
		else t = s1[i] - 'A' + 10;
		n = n * d1 + t;
	}
	if (n) s2 = "";//考虑s2为0的情况
	while (n > 0) {
		t = n % d2;
		n /= d2;
		if (t <= 9)s2 = to_string(t) + s2;
		else s2 = (char)(t - 10 + 'A') + s2;
	}
}
void change(string &s)
{
	for (int i = 0; i < s.size(); ++i) {
		if (islower(s[i])) s[i] = toupper(s[i]);
	}
}
int main()
{
	string s1, s2;
	int d1, d2;
	cin >> d1 >> s1 >> d2;
	change(s1); s2 = "0";//s2可能为零
	conversion(s1, s2, d1, d2);
	cout << s2 << endl;
	return 0;
}
