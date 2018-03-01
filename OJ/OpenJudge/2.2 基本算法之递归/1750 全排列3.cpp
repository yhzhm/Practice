// Created by Hz Yang on 2017.04
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char arr[10];int len;
void perm()
{
	do{
		for(int i=0;i<len;++i)cout<<arr[i];
		cout<<endl;
	}while (next_permutation(arr,arr+len));
}
int main()
{

	gets(arr);
	len=strlen(arr);
	perm( );
	return 0;
}