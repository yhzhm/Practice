#include<iostream>
using namespace std; 
bool prime(int x)
{
	int i=2;
	while(x%i!=0 && i*i<=x) i++;
	return i*i>x && x>1;
}

bool isPrime1 (int x)
{
	if(x<=1) return false;
	for(int i=2;i<x;i++){
		if(x%i==0) return false;
	}
	return true;
}

bool isPrime2 (int x)
{
	if(x==2) return true;
	if(x<2 || x%2==0) return false;
	for(int i=3;i*i<=x;i=i+2){
		if(x%i==0) return false;
	}
	return true;
} 

//埃拉托色尼筛选法 
bool p[1000];
void erators(int n) 
{
	int j;
	for(int i=0;i<=n;i++)
		p[i]=true;
	p[0]=p[1]=false;
	for(int i=2;i*i<=n;i++){
		if(p[i]){
			j=i+i;
			while(j<=n){
				p[j]=false;
				j=j+i;
			}
		}
	}
}
int main()
{
	
	return 0;
}


