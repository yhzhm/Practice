#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n>>s;
	for(string::size_type i=0;i!=s.size();i++){
		s[i]=(s[i]+n-'a')%26+'a';
	}
	cout<<s<<endl;
}
