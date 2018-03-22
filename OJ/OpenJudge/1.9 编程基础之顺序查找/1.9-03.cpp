#include<bits/stdc++.h>
using namespace std;
int main()
{
	int max = 0, n1, n2, d = 0;
	for (int i = 1; i <= 7; ++i) {
		cin >> n1 >> n2;
		if (max < n1 + n2) {
			max = n1 + n2;
			d = i;
		}
	}
	cout << d << endl;
	return 0;
}