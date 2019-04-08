// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> opt;
stack<int> num;
vector<char> news;
int n;
int check(char c)
{
	if (isdigit(c)) return 9;
	else if (c == '(') return 1;
	else if (c == ')') return 2;
	else if (c == '+') return 3;
	else if (c == '-') return 4;
	else if (c == '*') return 5;
	else if (c == '/') return 6;
	else return 7;
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

int main()
{
	getline(cin, s);
	cout << s << endl;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		// cout << i << ' ' << check(c) << endl;
		switch (check(c)) {
		case 1:
			opt.push(c); break;
		case 2:
			while (opt.size()) {
				if (check(opt.top() == 2)) {opt.pop(); break;}
				else {news.push_back(opt.top()); opt.pop();}
			}
			break;
		case 3: case 4: case 5: case 6:
		case 7:
		{	int x = check_priority(c), y = 0;
			if (opt.size()) y = check_priority(opt.top());
			while (opt.size() && x <= y) {
				news.push_back(opt.top()); opt.pop();
				if (opt.size()) y = check_priority(opt.top());
				else y = 0;
			}
			opt.push(c);
			break;
		}
		case 9: news.push_back(c); break;
		default: break;
		}
	}
	// cout << "ok1";
	while (opt.size()) news.push_back(opt.top()), opt.pop();
	for (int i = 0; i < news.size(); ++i) cout << news[i];
	cout << endl;
	for (int i = 0; i < news.size(); ++i) {
		if (isdigit(news[i])) {
			n = n * 10 + (news[i] - 48);
		}
		else {
			if (n) {
				num.push(n);
				n = 0;
			}
			char c = news[i];
			int x = num.top(); num.pop();
			int y = num.top(); num.pop();
			switch (check(c)) {
			case 3: num.push(x + y); break;
			case 4: num.push(x - y); break;
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