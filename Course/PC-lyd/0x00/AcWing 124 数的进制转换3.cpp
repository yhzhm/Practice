// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		string a_line, b_line;
		cin >> a >> b >> a_line;

		vector<int> number;
		for (auto c : a_line) {
			if (c >= '0' && c <= '9') number.push_back(c - '0');
			if (c >= 'A' && c <= 'Z') number.push_back(c - 'A' + 10);
			if (c >= 'a' && c <= 'z') number.push_back(c - 'a' + 36);
		}
		reverse(number.begin(), number.end());

		vector<int> res;
		while (number.size()) {
			int r = 0;
			for (int i = number.size() - 1; i >= 0; --i) {
				number[i] += r * a;
				r = number[i] % b;
				number[i] /= b;
			}
			res.push_back(r);
			while (number.size() && number.back() == 0) number.pop_back();
		}

		reverse(res.begin(), res.end());
		for (auto x : res) {
			if (x <= 9) b_line += char(x + '0');
			if (x >= 10 && x <= 35) b_line += char(x + 'A' - 10);
			if (x >= 36) b_line += char(x + 'a' - 36);
		}

		cout << a << ' ' << a_line << endl;
		cout << b << ' ' << b_line << endl;
		cout << endl;
	}
	return 0;
}
