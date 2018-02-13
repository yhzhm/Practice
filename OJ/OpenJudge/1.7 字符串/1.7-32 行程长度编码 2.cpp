//
// Created by Hz Yang on 2017/4/6.
//
#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    string::size_type i, count = 1;
    for (i = 0; i < s.size(); ++i) {
        if (toupper(s[i]) == toupper(s[i + 1])) {
            count++;
            continue;
        } else {
            printf("(%c,%llu)", toupper(s[i]), count);
            count = 1;
        }
    }
    return 0;
}