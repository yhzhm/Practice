// Created by Hz Yang on 2019.05
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<int> nums;
stack<char> ops;

void cal()
{
	int a = nums.top(); nums.pop();
	int b = nums.top(); nums.pop();
	char c = ops.top(); ops.pop();
	int d;
	if (c == '+') d = b + a;
	else if (c == '-') d = b - a;
	else if (c == '*') d = b * a;
	else if (c == '/') d = b / a;
	else {// ^运算
		d = 1;
		while (a--) d *= b;
	}
	nums.push(d);
}

int main()
{
	string str;
	cin >> str;
	string left;//在左侧添加和字符串等长的左括号，防止右括号比左括号多（左多不影响结果，右多会影响计算）
	for (int i = 0; i <= str.size(); ++i) left += '(';
	str = left + str + ')';

	for (int i = 0; i < str.size(); ++i) {
		char c = str[i];
		if (isdigit(c)) {//如果是数字，累加后入nums栈
			int j = i, t = 0;
			while (isdigit(str[j]))	t = t * 10 + str[j] - '0', j++;
			i = j - 1, nums.push(t);
		} else {
			if (c == '+' || c == '-') {
				if (c == '-' && i && !(isdigit(str[i - 1]) || str[i - 1] == ')')) {//'-'是负号的情况，进行特判
					// if (c == '-' && !isdigit(str[i - 1]) && str[i - 1] != ')') { //与上一行同效
					int j = i + 1, t = 0;//i+1:负号后面的那一位开始
					while (isdigit(str[j])) t = t * 10 + str[j] - '0', j++;
					i = j - 1, nums.push(-t);
				} else {
					while (ops.top() != '(') cal();
					ops.push(c);
				}
			}
			else if (c == '*' || c == '/') {
				while (ops.top() == '*' || ops.top() == '/' || ops.top() == '^') cal();
				ops.push(c);
			}
			else if (c == '^') {
				while (ops.top() == '^') cal();
				ops.push(c);
			}
			else if (c == ')') {//右括号时，将括号内计算完毕（此时括号内优先级相同，可从右往左依次计算）
				while (ops.top() != '(') cal();
				ops.pop();
			}
			else if (c == '(') ops.push(c);
			else puts("invalid operator!");
		}
	}

	cout << nums.top() << endl;
	return 0;
}

/*
遇到数字：转换成数字后，入数字栈
负数进行特判，'-'号前不是数字，并且'-'号前不是')'  为判断i是否为0，是因为已在左侧加入左括号，所以第一个'-'不可能出现在0位
遇到字符：
左括号，入栈；
右括号，将当前括号内计算完毕，结束时弹出左括号；
计算符，和栈顶计算符比较，如果栈顶计算符优先级高于等于当前计算符，则栈顶出栈进行计算，结束后将当前计算符入栈

 */