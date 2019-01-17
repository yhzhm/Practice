<<<<<<< HEAD
#include <iostream>
#include <algorithm>
=======
// Created by Hz Yang on 2017.05
// #include <bits/stdc++.h>
#include <iostream>
>>>>>>> 1228bb1643cb3521c30396d68938d8cf2d96e1ca
using namespace std;
bool isp(int n)
{
<<<<<<< HEAD
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
=======
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cout << i << ' ';
    } 
    return 0;
>>>>>>> 1228bb1643cb3521c30396d68938d8cf2d96e1ca
}
int main()
{
	int x, y, sum = 0;
	cin >> x >> y;
	if (x > y) swap(x, y);
	for (int i = x; i <= y; ++i) {
		if (isp(i) == 1) {
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}