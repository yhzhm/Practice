// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[32];
	for (int i = 0; i < 31; i++) {
		a[i] = 1 << i;
		cout << a[i] << ' ';
	}
	return 0;
}