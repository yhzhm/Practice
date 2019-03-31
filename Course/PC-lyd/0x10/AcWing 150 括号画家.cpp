// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
string s;
stack<char> st;
int ans, cnt;
bool check(char c)//是否是左括号
{
	return (c == '(' || c == '[' || c == '{');
}

bool check2(char c1, char c2)//c1：栈顶，c2：右括号，是否和栈顶是一对匹配的括号
{
	return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
}

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (check(s[i])) st.push(s[i]);//如果是左括号，入栈
		else if (st.size() && check2(st.top(), s[i])) cnt++, st.pop();//右括号和栈顶匹配（栈非空），计数，将栈顶出栈
		else st.push(s[i]),	cnt = 0;//栈空或右括号与栈顶不匹配，入栈，计数器清零
		ans = max(ans, cnt);//每操作一次都更新答案
	}
	cout << ans * 2 << endl;//长度需要乘2
	return 0;
}
/*
//写法2:区别在于ans在不匹配时才更新
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (check(s[i])) st.push(s[i]);//如果是左括号，入栈
		else if (st.size() && check2(st.top(), s[i])) cnt++, st.pop();//右括号和栈顶匹配（栈非空），计数，将栈顶出栈
		else st.push(s[i]), ans = max(ans, cnt), cnt = 0;//不匹配时再更新答案
	}
	cout << max(ans, cnt) * 2 << endl;//因为可能更新没有被触发，所以需要max
	return 0;
}
*/