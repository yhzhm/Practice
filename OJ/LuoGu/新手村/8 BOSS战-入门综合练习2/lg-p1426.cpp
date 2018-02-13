#include <iostream>
using namespace std;
int main()
{
 
	double s,x,p=0.0,m=7.0;
	int d=0;
	cin>>s>>x;
	while(p<=s+x){
		if(p>=s-x&&p<=s+x) {
			++d;
			if(d==2)	{ cout<<'y'<<endl;return 0; }
		} 
		else d=0;
		p+=m;
		m*=0.98;
	}
	cout<<'n'<<endl;
	return 0;
}
