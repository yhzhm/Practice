#include <bits/stdc++.h>
using namespace std;
int main()
{
	string x, s = "";
	while (cin.peek() != '\n' && cin >> x) {
		s = x + ' ' + s;
	}
	cout << s << endl;
	return 0;
}
