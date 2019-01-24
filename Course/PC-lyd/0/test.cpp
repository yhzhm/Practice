// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
int d[100];
int main()
{
	for (int i = 0; i < 3; ++i) d[i] = 65 + i;
	do {
		for (int i = 0; i < 3; ++i) cout << (char)d[i] << ' ';
		cout << endl;
	} while (next_permutation(d, d + 3));
	return 0;
}