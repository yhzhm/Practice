#include<iostream>
using namespace std;
int main()
{
	string a[100],s1,s2;
	int j=0;
	while(cin.peek()!='\n'){
		cin>>a[j];
		j++;
	}
	cin>>s1>>s2;
	for(int i=0;i<j;i++){
		if(a[i]==s1) cout<<s2;
		else cout<<a[i];
		cout<<' ';
	}
	return 0;
}


