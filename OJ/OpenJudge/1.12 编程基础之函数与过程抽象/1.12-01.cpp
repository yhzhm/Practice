// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	char c;
	cin >> a >> c >> b;
	switch (c) {
	case '+': cout << a + b; break;
	case '-': cout << a - b; break;
	case '*': cout << a * b; break;
	case '/': cout << a / b; break;
	case '%': cout << a % b; break;
	default: break;
	}
	return 0;
}