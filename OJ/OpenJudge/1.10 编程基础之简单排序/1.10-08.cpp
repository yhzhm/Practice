// Created by Hz Yang on 2018.03
#include <bits/stdc++.h>
using namespace std;
struct patient
{
	int no, age;
	string id;

};
bool comp(patient a, patient b)
{
	if (a.age >= 60 && b.age < 60) return true;
	if (a.age < 60 && b.age >= 60) return false;
	if (a.age >= 60 && b.age >= 60) {
		if (a.age != b.age) return a.age > b.age;
		else return a.no < b.no;
	}
	if (a.age < 60 && b.age < 60) return a.no < b.no;
	return false;
}
int main()
{
	int n;
	cin >> n;
	patient p[n];
	for (int i = 0; i < n; ++i) {
		p[i].no = i + 1;
		cin >> p[i].id >> p[i].age;
	}
	sort(p, p + n, comp);
	for (int i = 0; i < n; ++i) {
		cout << p[i].id << endl;
	}
	return 0;
}