#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	for(string::size_type ix=0;ix!=a.size();++ix){
		a[ix]=tolower(a[ix]);
	}
	for(string::size_type ix=0;ix!=b.size();++ix){
		b[ix]=tolower(b[ix]);
	}
	a=' '+a+' ';
	b=' '+b+' ';
	string::size_type first=b.find(a);
	if(first==string::npos){
		cout<<-1<<endl;
	}
	else{
		string::size_type pos=first;
		int count=0;
		while(pos!=string::npos){
			++count;
			pos=b.find(a,pos+1);
		}
		cout<<count<<" "<<first<<endl;
	}
//	else{
//		string::size_type first=b.find_first_of(a);
//		find_first_of is not usefull in this program,this function will 
//		"Finds the first character equal to one of the characters in str as if by"
//		string::size_type pos=b.find(a);
//		cout<<pos<<" "<<first<<endl;
//	}
	return 0;
}
