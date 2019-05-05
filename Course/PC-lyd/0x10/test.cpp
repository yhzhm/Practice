// Created by Hz Yang on 2019.04
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 1e5;
int main()
{
	double n = 200000;
	for (int i = 1; i <= 10; ++i)
		n = n * 1.05, printf("%.2f\n", n );
	return 0;
}