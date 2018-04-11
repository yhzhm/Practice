// Created by Hz Yang on 2018.04
#include <bits/stdc++.h>
using namespace std;
struct ha {
	int d;
	string m;
} haab[366];
struct ho {
	int n;
	string s;
} holly[261];
string shaab[20] = {" ", "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
                    "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
                   };
string sholly[21] = {" ", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk",	"ok",
                     "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
                    };
int n;
int change(string s)
{
	int sum = 0;
	string::size_type i;
	for (i = 0; i < s.size() - 1; ++i) {
		sum = sum * 10 + (s[i] - '0');
	}
	return sum + 1;
}
int check(string s)
{
	int i;
	for (i = 1; i <= 19; ++i) {
		if (shaab[i] == s) break;
	}
	return i - 1;
}
int main()
{
	// n = 0; //构造haab年表
	// for (int i = 1; i <= 18; ++i) {
	// 	for (int j = 1; j <= 20; ++j) {
	// 		n++;
	// 		haab[n].d = j - 1;
	// 		haab[n].m = shaab[i];
	// 	}
	// }
	// for (int i = 0; i < 5; ++i) {
	// 	n++;
	// 	haab[n].d = i;
	// 	haab[n].m = shaab[19];
	// }
	//构造holly年表
	for (int i = 1; i <= 260; ++i) {
		int t = i % 13;
		holly[i].n = (t ? t : 13);
		t = i % 20;
		holly[i].s = sholly[t ? t : 20];
	}
	cin >> n;
	cout << n << endl;
	// for (int i = 1; i <= 40; ++i) {
	// 	cout << holly[i].n << holly[i].s << ' ';
	// }
	for (int i = 1; i <= n; ++i) {
		string day, month; int year, yue, dd;
		cin >> day >> month >> year;
		yue = check(month);
		dd = (year) * 365 + yue * 20 + change(day);
		year = dd / 260 ;
		dd = dd % 260;
		if (!dd) dd = 260;
		cout << holly[dd].n << ' ' << holly[dd].s << ' ' << year << endl;
	}
	return 0;
}