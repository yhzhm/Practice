// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}
	int *p, sum = 0;
	for (p = a; p != &a[10]; ++p) {
		sum += *p;
	}
	cout << sum << endl;
	return 0;
}