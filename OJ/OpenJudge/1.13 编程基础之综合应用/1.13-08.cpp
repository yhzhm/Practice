// Created by Hz Yang on 2018.11
#include <bits/stdc++.h>
using namespace std;
bool isleap(int year)
{
	return (year % 4 == 0 && year % 100) || year % 400 == 0;
}
int cntdays(int day, int month, int year)
{
	int sum = 0;
	int monthdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 2000; i < year; ++i) {
		if (isleap(i)) sum += 366;
		else sum += 365;
	}
	for (int i = 1; i < month; ++i) {
		sum += monthdays[i];
		if (i == 2 && isleap(year)) sum++;
	}
	sum += day;
	return sum;
}
int main()
{
	int n, hour, minute, second, day, month, year;
	int mhour, mminute, msecond, mday, mmonth, myear;
	int total_days, total_seconds;
	// double total_mseconds;
	cin >> n;
	for (; n > 0; n--) {
		scanf("%d:%d:%d %d.%d.%d", &hour, &minute, &second, &day, &month, &year);
		total_days = cntdays(day, month, year);
		myear = total_days / 1000; total_days %= 1000;
		mmonth = total_days / 100 + 1;;
		mday = total_days % 100;

		total_seconds = hour * 60 * 60 + minute * 60 + second;
		total_seconds = floor(total_seconds / 0.684);
		mhour = total_seconds / 10000; total_seconds %= 10000;
		mminute = total_seconds / 100;
		msecond = total_seconds % 100;
		printf("%d:%d:%d %d.%d.%d\n", mhour, mminute, msecond, mday, mmonth, myear);
	}

	return 0;
}