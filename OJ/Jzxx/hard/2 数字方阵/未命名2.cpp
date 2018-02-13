#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string a, s1, s2;
	vector<string> v;
	while (cin.peek() != '\n') {
		cin >> a;
		v.push_back(a);
	}
	cin >> s1 >> s2;
	for (int i = 0; i != v.size(); ++i) {
		if (v[i] == s1) v[i] = s2;
		cout << v[i] << ' ';
	}
	return 0;
}
