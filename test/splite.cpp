// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin >> m;
	int ax, ay, bx, by, cx, cy, count = 0;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	for (int i = ax; i <= ay; ++i) {
		for (int j = bx; j <= by; ++j) {
			int x = m - i - j;
			if (x >= cx && x <= cy) count++;
		}
	}
	cout << count << endl;
	return 0;
}