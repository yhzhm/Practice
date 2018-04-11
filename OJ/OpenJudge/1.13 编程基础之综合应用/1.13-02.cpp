#include<bits/stdc++.h>
using namespace std;
int main()
{
	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int w, x, day = 0;
	cin >> w;
	x = 6 - w % 7;
	for (int i = 1; i <= 12; ++i) {
		for (int j = 1; j <= month[i]; ++j) {
			day++;
			if (day % 7 == x && j == 13) cout << i << endl;
		}
	}
	return 0;
}
