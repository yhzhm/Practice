#include <bits/stdc++.h>
using namespace std;

double f()
{
	string s;
	cin>>s;
	switch(s[0]){
		case '+':return f() + f();
		case '-':return f() - f();
		case '*':return f() * f();
		case '/':return f() / f();
		default:return atof(s.c_str());
		break;
	}
}
int main()
{
	//cout<<f()<<endl;
	printf("%f\n",f());
	return 0;
}	