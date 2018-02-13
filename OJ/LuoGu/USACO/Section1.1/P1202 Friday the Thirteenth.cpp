//
// Created by Hz Yang on 2017/8/24.
// 输出顺序是周六 周日 周一~周五
#include <cstdio>
#include <iostream>

using namespace std;

int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day=0;
int week[7];

bool check(int n)
{
    if(n%4==0 && n%100!=0 || n%400==0) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1900; i < 1900 + n ; ++i) {
        if (check(i)) month[2]=29;
        else month[2]=28;
        for (int j = 1; j <= 12 ; ++j) {
            for (int k = 1; k <= month[j]; ++k) {
                ++day;
                if(k==13) ++week[day%7];
            }
        }
    }
    printf("%d %d %d %d %d %d %d",week[6],week[0],week[1],week[2],week[3],week[4],week[5]);
    return 0;
}


