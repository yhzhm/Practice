#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n = 0;
	string s;
	cin >> s;
	for (int i = 2; i < s.size(); ++i) {
		n += (s[i] - '0') * 1.0 / pow(8, i - 1);
	}
	printf("%s [8] = %.50g [10]", s.c_str(), n);
	return 0;
}