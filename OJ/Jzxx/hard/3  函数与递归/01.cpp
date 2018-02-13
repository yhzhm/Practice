#include<iostream>
using namespace std;
int my_max(int x,int y,int z)
{
	return max(max(x,y),z);
}
int main()
{
	int a,b,c;
	double d;
	cin >> a >> b >> c;
	d=(double)my_max(a,b,c ) 
		/ ( my_max(a+b,b,c) 
		* my_max(a,b,b+c) );
	printf("%.6f\n",d);
	return 0;
}


