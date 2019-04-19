// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
string s, sum;//s:读入的一行字符串，sum：保存转换时的数字
stack<char> opt;//中转后时的操作符栈
stack<int> num;//计算后缀表达式时的数字栈
vector<string> vstr;//保存转换后的后缀表达式
int n;
int check(char c)//判断是何种操作符
{
	if (isdigit(c)) return 9;
	if (c == '(') return 1;
	if (c == ')') return 2;
	if (c == '-') return 3;
	if (c == '+') return 4;
	if (c == '*') return 5;
	if (c == '/') return 6;
	return 7;
}

int check_priority(char c)//计算符优先级
{
	if (c == '(') return 1;
	if (c == '+' || c == '-') return 2;
	return 3;
}

int qmi(int x, int y)//快速幂
{
	int res = 1;
	while (y) {
		if (y & 1) res = res * x;
		x = x * x;
		y >>= 1;
	}
	return res;
}

int tonum(string s)//将string保存的数字转换为int
{
	int res = 0, i = 0, flag = 1;
	if (s[0] == '-') flag = -1, i = 1;//是否负数
	for (   ; i < s.size(); ++i)
		res = res * 10 + (s[i] - 48);
	return res * flag;
}

int main()
{
	getline(cin, s);
	//将中缀表达式转换为后缀表达式
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i]; string sb = "";//sb:用于将char转换为string
		switch (check(c)) {
		case 1:
			opt.push(c); break;//左括号直接入栈
		case 2:
			while (opt.size()) {//右括号时，弹出栈中左括号上的所有操作符
				if (check(opt.top()) == 1) {opt.pop(); break;}//左括号直接弹出
				else {vstr.push_back(sb + opt.top()); opt.pop();}//其它符号加入后缀表达式
			}
			break;
		case 3: sum += '-', c = '+'; case 4:  case 5: case 6://将减法转换为加法
		case 7://将栈中比当前操作符优先级高的操作符弹出，加入后缀表达式
		{	int x = check_priority(c), y = 0;
			if (opt.size()) y = check_priority(opt.top());
			while (opt.size() && x <= y) {
				vstr.push_back(sb + opt.top()); opt.pop();
				if (opt.size()) y = check_priority(opt.top());
				else y = 0;
			}
			opt.push(c);//当前操作符入栈
			break;
		}
		case 9:
			sum += c;//累加数字
			if (!isdigit(s[i + 1]))vstr.push_back(sum), sum = "";
			break;
		default: break;
		}
	}
	while (opt.size()) {//弹出栈中剩余操作符，加入后缀表达式
		string sb = "";
		vstr.push_back(sb + opt.top());
		opt.pop();
	}

	// for (int i = 0; i < vstr.size(); ++i) cout << vstr[i] << ' ';
	// cout << endl;
	// while (num.size()) cout << num.top() << ' ', num.pop();
	// cout << endl;

	//计算后缀表达式
	for (int i = 0; i < vstr.size(); ++i) {
		char c = vstr[i][0];
		if (isdigit(c) || c == '-') {//遇到数字转换后入num栈
			n = tonum(vstr[i]);
			num.push(n);
		} else if (num.size() > 1) {//遇到操作符，从num栈中取出两个数字，计算后将结果入num栈
			int	y = num.top(); num.pop();
			int	x = num.top(); num.pop();
			switch (check(c)) {
			case 1: case 2: break;
			case 3:
			case 4: num.push(x + y); break;
			case 5: num.push(x * y); break;
			case 6: num.push(x / y); break;
			case 7: num.push(qmi(x, y)); break;
			default: break;
			}
		}

	}
	cout << num.top() << endl;//栈中剩余数字即结果
	return 0;
}