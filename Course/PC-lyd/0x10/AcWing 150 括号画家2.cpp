// Created by Hz Yang on 2019.05
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	string str;
	cin >> str;
	stack<int> stk;//存储下标

	int res = 0;
	for (int i = 0; i < str.size(); ++i) {
		char c = str[i];
		if (stk.size()) {//栈非空时，如果匹配，则弹出，否则直接插入
			char t = str[stk.top()];
			if (c == ')' && t == '(' || c == ']' && t == '[' || c == '}' && t == '{') stk.pop();
			else stk.push(i);
		}
		else stk.push(i);//栈为空时直接插入

		if (stk.size()) res = max(res, i - stk.top());//栈顶元素与当前元素之间的下标之差，为已成功配对后删除的元素数量
		else res = max(res, i + 1);//栈为空时，说明所有元素都成功配对，元素个数为i+1（从0开始）
	}

	cout << res << endl;
	return 0;
}