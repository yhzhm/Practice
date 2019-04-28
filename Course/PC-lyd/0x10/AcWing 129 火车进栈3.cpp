// Created by Hz Yang on 2019.04
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, cnt = 20, state3 = 1; //未进栈数
vector<int> state1;//出栈序列
stack<int> state2;//栈中元素

void dfs()
{
	if (!cnt) return;
	if (state1.size() == n) {
		cnt --;
		for (auto x : state1) cout << x;
		cout << endl;
		return;
	}
	if (state2.size()) {
		state1.push_back(state2.top());
		state2.pop();
		dfs();
		state2.push(state1.back());
		state1.pop_back();
	}

	if (state3 <= n) {
		state2.push(state3);
		state3++;
		dfs();
		state3--;
		state2.pop();
	}
}

int main()
{
	cin >> n;
	dfs();
	return 0;
}

/*
维护好3个state状态
 */