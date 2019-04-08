// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
string s, sum;
stack<char> opt;
stack<int> num;
vector<string> vstr;
int n;
int check(char c)
{
	if (isdigit(c)) return 9;
	if (c == '(') return 1;
	if (c == ')') return 2;
	if (c == '+') return 4;
	if (c == '-') return 3;
	if (c == '*') return 5;
	if (c == '/') return 6;
	return 7;
}

int check_priority(char c)
{
	if (c == '(') return 1;
	else if (c == '+' || c == '-') return 2;
	else return 3;
}

int qmi(int x, int y)
{
	int res = 1;
	while (y) {
		if (y & 1) res = res * x;
		x = x * x;
		y >>= 1;
	}
	return res;
}

int tonum(string s)
{
	int res = 0, i = 0, flag = 1;
	if (s[0] == '-') flag = -1, i = 1;
	for (; i < s.size(); ++i) {
		res = res * 10 + (s[i] - 48);
	}
	return res * flag;
}

int main()
{
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i]; string sb = "";
		switch (check(c)) {
		case 1:
			opt.push(c); break;
		case 2:
			while (opt.size()) {
				if (check(opt.top()) == 1) {opt.pop(); break;}
				else {vstr.push_back(sb + opt.top()); opt.pop();}
			}
			break;
		case 3: sum += '-', c = '+'; case 4:  case 5: case 6:
		case 7:
		{	int x = check_priority(c), y = 0;
			if (opt.size()) y = check_priority(opt.top());
			while (opt.size() && x <= y) {
				vstr.push_back(sb + opt.top()); opt.pop();
				if (opt.size()) y = check_priority(opt.top());
				else y = 0;
			}
			opt.push(c);
			break;
		}
		case 9:
			sum += c;
			if (!isdigit(s[i + 1]))vstr.push_back(sum), sum = "";
			break;
		default: break;
		}
	}
	while (opt.size()) {
		string sb = "";
		vstr.push_back(sb + opt.top());
		opt.pop();
	}

	// for (int i = 0; i < vstr.size(); ++i) cout << vstr[i] << ' ';
	// cout << endl;
	// while (num.size()) cout << num.top() << ' ', num.pop();
	// cout << endl;
	for (int i = 0; i < vstr.size(); ++i) {
		char c = vstr[i][0];
		if (isdigit(c) || c == '-') {
			n = tonum(vstr[i]);
			num.push(n);
		} else if (num.size() > 1) {
			int	y = num.top(); num.pop();
			int	x = num.top(); num.pop();
			switch (check(c)) {
			case 1: case 2: break;
			case 3: num.push(x + y); break;
			case 4: num.push(x + y); break;
			case 5: num.push(x * y); break;
			case 6: num.push(x / y); break;
			case 7: num.push(qmi(x, y)); break;
			default: break;
			}
		}

	}
	cout << num.top() << endl;
	return 0;
}