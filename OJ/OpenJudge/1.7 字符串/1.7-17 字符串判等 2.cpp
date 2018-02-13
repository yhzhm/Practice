// Created by Hz Yang on 2017.03
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	for (int j = 0; j < a.length(); j++)
	{
		while (a[j] == ' ') a.erase(j, 1);
		if (islower(a[j])) a[j] = toupper(a[j]);
	}
	for (int j = 0; j < b.length(); j++)
	{
		while (b[j] == ' ') b.erase(j, 1);
		if (islower(b[j])) b[j] = toupper(b[j]);
	}
	if (a == b) cout << "YES";
	else cout << "NO";
	return 0;
}
