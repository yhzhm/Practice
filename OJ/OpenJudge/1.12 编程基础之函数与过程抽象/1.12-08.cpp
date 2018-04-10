#include<bits/stdc++.h>
using namespace std;
int check(char x)
{
	if (isupper(x)) return x - 'A';
	else return x - 'a';
}
char dec(char x, int n)
{
	if (isupper(x)) {
		x = x - n;
		if (x < 65) x += 26;
		return x;
	}
	else {
		x = x - n;
		if (x < 97) x += 26;
		return x;
	}
}
int main()
{
	string k, c;
	int p = 0, n;
	cin >> k >> c;
	for (int i = 0; i < c.size(); ++i) {
		n = check(k[p++]);
		cout << dec(c[i], n);
		if (p == k.size()) p = 0;
	}
	return 0;
}
