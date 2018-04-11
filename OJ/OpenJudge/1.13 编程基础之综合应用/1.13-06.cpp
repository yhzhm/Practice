//数据范围最大60位，超范围
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s; int t, sum = 0;
	cin >> s ;
	string::size_type p = 0, n = s.size();
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {p = i + 1; continue;}
		else break;
	}
	for (int i = p; i < s.size(); ++i) {
		sum = sum * 10 + (s[i] - '0');
	}
	string ss = s + s;
	string x;
	// string ss = to_string(sum);
	// ss = ss + ss;
	bool flag = 1;
	for (int i = 1; i <= n; ++i) {
		x = to_string(sum * i);
		if (ss.find(x) == string::npos) {flag = 0; break;}
	}
	cout << flag << endl;
	return 0;
}