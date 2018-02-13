// Created by Hz Yang on 2017.03
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;
string change(string s)
{
	string x="";
	for(int i=0;i<s.size();i++){
		if(s[i]!=' ' ) {
			if(islower(s[i])) s[i]=toupper(s[i]);
			x=x+s[i];
		}
	}
	return x;
}
int main()
{
	string a, b;
	getline(cin, a);a=change(a);
	getline(cin, b);b=change(b);
	if (a == b) cout << "YES";
	else cout << "NO";
	return 0;
}
